/*==================================================================================================
PROGRAMMER:			Yang Wang
COURSE:				CSC 525/625
MODIFIED BY:			N/A
LAST MODIFIED DATE:	XXX
DESCRIPTION:			Demo: Display in 3D.
NOTE:					N/A
FILES:					displayIn3D.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <string>
#include <GL/glut.h>				// include GLUT library

using namespace std;

const float RED[] = { 1, 0, 0 }, BLUE[] = { 0, 0, 1 }, GREEN[] = { 0, 1, 0 };

int vertices[][3] = { 60, 55, 40,
					  60,-50, 40,
					  65, 90, -70,
					  65, 0, -70,
					  -70, 70, 20,
					  -70, -20, 20};

//***********************************************************************************
void drawSide(const float color[], int v1[], int v2[], int v3[], int v4[])
{
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glColor3fv(color);

	glVertex3iv(v1);
	glVertex3iv(v2);
	glVertex3iv(v3);
	glVertex3iv(v4);
	glEnd();
}

//***********************************************************************************
void drawObjects()
{
	drawSide(RED, vertices[0], vertices[1], vertices[3], vertices[2]);
	drawSide(BLUE, vertices[4], vertices[5], vertices[1], vertices[0]);
	drawSide(GREEN, vertices[2], vertices[3], vertices[5], vertices[4]);
}


void printVertexLabel(string container, string label, int p[3])
{
	glRasterPos3iv(p);
	container = label;
	for (int i = 0; i < 2; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, container[i]);
}


//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	gluLookAt(0, 0, 0, -60, -70, -60, 0, 1, 0);

	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex3i(x, 0, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex3i(0, y, 0);
	for (int z = -150; z <= 150; z++) // draw Y-axis
		glVertex3i(0, 0, z);
	glEnd();


	glRasterPos3i(0, 150, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');

	glRasterPos3i(150, 0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'X');

	string placeholder;
	printVertexLabel(placeholder, "V0", vertices[0]);
	printVertexLabel(placeholder, "V1", vertices[1]);
	printVertexLabel(placeholder, "V2", vertices[2]);
	printVertexLabel(placeholder, "V3", vertices[3]);
	printVertexLabel(placeholder, "V4", vertices[4]);
	printVertexLabel(placeholder, "V5", vertices[5]);
	drawObjects();

	glFlush();
}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);					// specify a background clor: white
	glOrtho(-200, 200, -200, 200, -200, 200);  // specify a viewing volume
	glEnable(GL_DEPTH_TEST);
}

//***********************************************************************************
void main()
{

	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Display in 3D");

	myInit();
	glutDisplayFunc(myDisplayCallback);

	glutMainLoop();
}
