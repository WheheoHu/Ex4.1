#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "glut.h"
static float fRotateTri = 0;
static float fRotateQuad = 0;
constexpr double fradius = 30;
constexpr double PI = 3.14159265357;
class CoordinateXYZ
{
public:
	CoordinateXYZ(int x_, int y_, int z_);
	int get_CoorX();
	int get_CoorY();
	int get_CoorZ();
private:
	int CoorX;
	int CoorY;
	int CoorZ;
};

CoordinateXYZ::CoordinateXYZ(int x_, int y_, int z_) :
	CoorX(x_),
	CoorY(y_),
	CoorZ(z_)

{
}

int CoordinateXYZ::get_CoorX()
{
	return CoorX;
}

int CoordinateXYZ::get_CoorY()
{
	return CoorY;
}

int CoordinateXYZ::get_CoorZ()
{
	return CoorZ;
}

std::vector<CoordinateXYZ> Triangle_Coordinates;
std::vector<CoordinateXYZ> Quad_Coordinates;
void displayFunc();
void Idlefunc();
void RenderATriangle();
//TODO finish this
void RenderAQuad();
void RenderACiecle();

int main() {
	Triangle_Coordinates.push_back(CoordinateXYZ(-40, -40, 0));
	Triangle_Coordinates.push_back(CoordinateXYZ(40, -40, 0));
	Triangle_Coordinates.push_back(CoordinateXYZ(0, 40, 0));

	Quad_Coordinates.push_back(CoordinateXYZ(-20, -20, 0));
	Quad_Coordinates.push_back(CoordinateXYZ(-20, 20, 0));
	Quad_Coordinates.push_back(CoordinateXYZ(20, 20, 0));
	Quad_Coordinates.push_back(CoordinateXYZ(20, -20, 0));

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Split-Screen");
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	//gluOrtho2D(-100, 100, -100, 100);
	glOrtho(-100, 100, -100, 100, -100, 100);

	glMatrixMode(GL_MODELVIEW);

	glutDisplayFunc(displayFunc);
	glutIdleFunc(Idlefunc);
	glutMainLoop();
}


void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glViewport(0, 0, 600, 600);
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 100, 0);
	glVertex3f(0, -100, 0);
	glVertex3f(-100, 0, 0);
	glVertex3f(100, 0, 0);
	glEnd();

	RenderATriangle();
	RenderAQuad();
	RenderACiecle();

	glutSwapBuffers();
}

void Idlefunc()
{
	fRotateTri += 0.05f;
	fRotateQuad += 0.05f;
	if (fRotateTri > 360)
	{
		fRotateTri = 0;
	}
	if (fRotateQuad > 360)
	{
		fRotateQuad = 0;
	}
	displayFunc();
}

void RenderATriangle()
{
	glColor3f(0.6, 0.6, 0.6);
	glLoadIdentity();
	//glRotatef(fRotateTri, 1, 0, 0);
	glViewport(0, 0, 300, 300);
	glBegin(GL_TRIANGLES);
	for (auto iter = Triangle_Coordinates.begin(); iter != Triangle_Coordinates.end(); iter++)
	{

		glVertex3f(iter->get_CoorX(), iter->get_CoorY(), iter->get_CoorZ());
	}
	glEnd();
}

void RenderAQuad()
{
	glColor3f(0.4, 0.5, 0.6);
	glLoadIdentity();
	//glRotatef(fRotateQuad, 0, 1, 0);
	glViewport(300, 0, 300, 300);
	glBegin(GL_QUADS);
	for (auto iter = Quad_Coordinates.begin(); iter != Quad_Coordinates.end(); iter++)
	{
		glVertex3f(iter->get_CoorX(), iter->get_CoorY(), iter->get_CoorZ());
	}
	glEnd();
}

void RenderACiecle()
{
	constexpr int angle_step = 1;
	glColor3f(0.6, 0.5, 0.4);
	glLoadIdentity();

	glViewport(150, 300, 300, 300);
	glBegin(GL_LINE_LOOP);
	for (int angle = 0; angle < 360; angle+=angle_step)
	{
		glVertex3f(fradius*std::cos(angle*PI / 180), fradius*std::sin(angle*PI / 180),0);
	}
	glEnd();
}
