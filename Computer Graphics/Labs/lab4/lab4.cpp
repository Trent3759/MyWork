/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		09/16/2016
DESCRIPTION:			Demo: drawing polygon and patterns
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					lab4.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>
#include <GL/glut.h>				// include GLUT library
using namespace std;

int SELECTION;


void drawStar() {
	glEnable(GL_POLYGON_STIPPLE);
	GLenum mode;

	GLubyte pattern[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x01, 0xf0,
		0x00, 0x00, 0x07, 0xf0, 0x0f, 0x00, 0x1f, 0xe0,
		0x1f, 0x80, 0x1f, 0xc0, 0x0f, 0xc0, 0x3f, 0x80,
		0x07, 0xe0, 0x7e, 0x00, 0x03, 0xf0, 0xff, 0x80,
		0x03, 0xf5, 0xff, 0xe0, 0x07, 0xfd, 0xff, 0xf8,
		0x1f, 0xfc, 0xff, 0xe8, 0xff, 0xe3, 0xbf, 0x70,
		0xde, 0x80, 0xb7, 0x00, 0x71, 0x10, 0x4a, 0x80,
		0x03, 0x10, 0x4e, 0x40, 0x02, 0x88, 0x8c, 0x20,
		0x05, 0x05, 0x04, 0x40, 0x02, 0x82, 0x14, 0x40,
		0x02, 0x40, 0x10, 0x80, 0x02, 0x64, 0x1a, 0x80,
		0x00, 0x92, 0x29, 0x00, 0x00, 0xb0, 0x48, 0x00,
		0x00, 0xc8, 0x90, 0x00, 0x00, 0x85, 0x10, 0x00,
		0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00
	};

	if (SELECTION == 1) {
		mode = GL_FILL;
	}
	else if (SELECTION == 2) {
		mode = GL_LINE;
	}
	else if (SELECTION == 3) {
		mode = GL_POINT;
	}
	else if (SELECTION == 4){
		glPolygonStipple(pattern);
	}
	glPointSize(10);
	glLineWidth(5);
	glColor3f(1, 0, 0);
	glPolygonMode(GL_FRONT, mode);
	glBegin(GL_POLYGON);
	glVertex2i(0, 80);
	glColor3f(0, 1, 0);
	glVertex2i(-70, -0);
	glColor3f(0, 0, 1);
	glVertex2i(-30, -60);
	glColor3f(1, 1, 0);
	glVertex2i(30, -60);
	glColor3f(0, 1, 1);
	glVertex2i(70, 0);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);


	glPointSize(1);		// change point size back to 1

	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex2i(x, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex2i(0, y);
	glEnd();


}



void menu(){
	cout << "Options" << endl;
	cout << "1. Fill Polygon" << endl;
	cout << "2. Outline Polygon" << endl;
	cout << "3. Points of Polygon" << endl;
	cout << "4. Patterned Polygon " << endl;

	cout << endl << "Enter your selection: ";

	cin >> SELECTION;
}





//***********************************************************************************
void myInit()
{
	glClearColor(0, 0, 0, 1);			// specify a background clor: white 
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawStar();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************


void main()
{
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Hex Drawing");	// create a titled window


	myInit();									// setting up

	menu();

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


