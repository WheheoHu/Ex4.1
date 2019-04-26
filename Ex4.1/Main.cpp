#include <iostream>
#include <vector>
#include "glut.h"
class CoordinateXY
{
public:
	CoordinateXY(int x_, int y_);
	int get_CoorX();
	int get_CoorY();
private:
	int CoorX;
	int CoorY;
};

CoordinateXY::CoordinateXY(int x_, int y_):
	CoorX(x_),
	CoorY(y_)
{
}

int CoordinateXY::get_CoorX()
{
	return CoorX;
}

int CoordinateXY::get_CoorY()
{
	return CoorY;
}



void displayFunc();
int main() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 300);
	glutCreateWindow("Split-Screen");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100, 100, -100, 100);

	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(displayFunc);
	glutMainLoop();
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, 600, 300);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0, 150);
	glVertex2f(0, -150);
	glEnd();


	glLoadIdentity();
	glFlush();
}
