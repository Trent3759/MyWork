/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		10/19/2016
DESCRIPTION:			Demo: Menus and Submenues
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					lab10.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <string>
#include <iostream>
#include <GL/glut.h>				// include GLUT library

using namespace std;

string INPUT;
int rasterX;
int rasterY;
void * FONT = GLUT_BITMAP_TIMES_ROMAN_24;
GLfloat GREEN[3] = { 0, 1, 0 };
GLfloat MAGENTA[3] = { 1, 0, 1 };
GLfloat CYAN[3] = { 0, 1, 1 };
GLfloat * FONTCOLOR = GREEN;

void drawAxis(){
	glPointSize(1);		// change point size back to 1

	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);	// use points to form X-/Y-axes
	for (int x = -150; x <= 150; x++) // draw X-axis
		glVertex2i(x, 0);
	for (int y = -150; y <= 150; y++) // draw Y-axis
		glVertex2i(0, y);
	glEnd();

	glRasterPos2i(0, 150);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'Y');

	glRasterPos2i(150, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 'X');
}


void typingText() {

	drawAxis(); //axis drawing code moved to a different function for code clarity. 

	glColor3fv(FONTCOLOR);

	glRasterPos2i(rasterX, rasterY);

	for (int i = 0; i < INPUT.length(); i++){
		glutBitmapCharacter(FONT, INPUT[i]);
	}
}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background clor: white 
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	typingText();
	glFlush(); // flush out the buffer contents
}

//***********************************************************************************

void type(unsigned char key, int x, int y){
	INPUT += key;
	rasterX = x - 200;
	rasterY = 200 - y;
	glutPostRedisplay(); //redraw display
}

void move(int x, int y) {
	rasterX = x - 200;
	rasterY = 200 - y;
	glutPostRedisplay(); //redraw display
}

void processColorOption(int option) {
	cout << "Color: " << option << endl;

	switch (option) {
	case 0: {
		FONTCOLOR = CYAN;
		break;
	} 
	case 1: {
		FONTCOLOR = MAGENTA;
		break;
	}
	case 2: {
		FONTCOLOR = GREEN;
	}
	}
	glutPostRedisplay(); //redraw display
}


void processFontOption(int option) {
	//this function will process font selection
	cout << "Font: " << option << endl;
	switch (option) {
	case 0: {
		FONT = GLUT_BITMAP_TIMES_ROMAN_24;
		break;
	}
	case 1: {
		FONT = GLUT_BITMAP_HELVETICA_18;
	}
	}
	glutPostRedisplay(); //redraw window
}


void processMenu(int option) {
	//process menu only has 1 function. Exit. If true, do it here. 
	if (option) {
		exit(0);
	}
}

void main()
{
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Text Drawing/Menu Testing");	// create a titled window

	
	int colorMenu = glutCreateMenu(processColorOption);
	
	glutAddMenuEntry("Cyan", 0);
	glutAddMenuEntry("Magenta", 1);
	glutAddMenuEntry("Green", 2);

	int fontMenu = glutCreateMenu(processFontOption);
	
	glutAddMenuEntry("Times Roman", 0);
	glutAddMenuEntry("Helvetica", 1);
	
	int mainMenu = glutCreateMenu(processMenu);
	glutAddSubMenu("Font Color", colorMenu);
	glutAddSubMenu("Font Style", fontMenu);
	glutAddMenuEntry("Exit Program", true);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	myInit();									// setting up
	
	glutMotionFunc(move);
	glutKeyboardFunc(type);
	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


