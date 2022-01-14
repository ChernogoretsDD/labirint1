#include "DemoWindow.h"

DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	set_title("OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glEnable(GL_DEPTH_TEST); // Испрвляет изображение
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0,								// угол обзора
			double(width()) / double(height()),	// соотношение
			0.1,								// расстояние до ближней
			20.0);								// расстояние до дальней;
}

void Cube(){
	glBegin(GL_QUADS);

	glEnable(GL_CULL_FACE);

	glColor3d(1.0, 0.0, 0.0);		// нижняя красная
		glVertex3d(-1.0,  1.0, -1.0);
		glVertex3d(1.0,  1.0, -1.0);
		glVertex3d( 1.0, -1.0, -1.0);
		glVertex3d(-1.0, -1.0, -1.0);


		glColor3d(0.0, 1.0, 1.0);		//верхняя бирюзовая
		glVertex3d(-1.0, -1.0,  1.0);
		glVertex3d( 1.0, -1.0,  1.0);
		glVertex3d( 1.0,  1.0,  1.0);
		glVertex3d(-1.0,  1.0,  1.0);


		glColor3d(0.0, 0.0, 1.0);		// боковая1 синяя
			glVertex3d(-1.0, 1.0,  1.0);
			glVertex3d(-1.0, -1.0, 1.0);
			glVertex3d(-1.0, -1.0, -1.0);
			glVertex3d(-1.0,  1.0, -1.0);

		glColor3d(1.0, 0.5, .0);		// боковая2 оранжевая
			glVertex3d(-1.0, -1.0,  1.0);
			glVertex3d(1.0, -1.0, 1.0);
			glVertex3d(1.0, -1.0, -1.0);
			glVertex3d(-1.0, -1.0, -1.0);

		glColor3d(0.0, 1.0, 0.0);		// боковая3 зеленая
			glVertex3d(1.0, -1.0,  1.0);
			glVertex3d(1.0, -1.0, -1.0);
			glVertex3d(1.0, 1.0, -1.0);
			glVertex3d(1.0, 1.0, 1.0);

		glColor3d(1.0, 1.0, 0.5);		// боковая4 желтая
			glVertex3d(1.0, 1.0,  1.0);
			glVertex3d(-1.0, 1.0, 1.0);
			glVertex3d(-1.0, 1.0, -1.0);
			glVertex3d(1.0, 1.0, -1.0);

	glEnd();

	}

void DemoWindow::render()
{

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); // очистка



	glLoadIdentity(); // MV = ед матрица

	gluLookAt(	3.0, 4.0, 2.0,		// координаты камеры
				0.0, 0.0, 0.0,		// координаты центра
				0.0, 0.0, 1.0);		// верхнее направление,	MV = C


	glRotated(_cube_angle, 0.0, 0.0, 1.0);
	glScaled( 0.4, 0.4, 0.4 ); // маштабируемость 


	glPushMatrix();// сохранение координат

	glTranslated(0.0, 0.0, -1.0); // сдигаемся по оси Y
		Cube();

	glTranslated(-2.5, 0.0, 0.0); // сдигаемся по оси X

	Cube();

	glTranslated(5.0, 0.0, 0.0); // сдигаемся по оси X

	Cube();

	glTranslated(-1.0, 0.0, 2.0); // сдигаемся по оси X и Y

	Cube();

	glTranslated(-2.5, 0.0, 0.0); // сдигаемся по оси X и Y

	Cube();

	glTranslated(1.25, 0.0, 2.0); // сдигаемся по оси X и Y

	Cube();

	glPopMatrix(); // возвращение обратно
}


void DemoWindow::update()
{
	_cube_angle += 0.1;
	if (_cube_angle >= 360.0)
		_cube_angle -= 360.0;
}
