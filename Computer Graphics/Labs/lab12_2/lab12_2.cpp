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
#include <math.h>
long double PI = 3.14159265358979323846264338327950288;
long long int ANGLE = (15 * PI) / 180;

using namespace std;
const int defaultCoords[4][3] = { { 100,100,0 },{ -100,100,0 },{ -100,-100,0 },{ 100,-100,0 } };
int coords[4][3] = { {100,100,0},{-100,100,0},{-100,-100,0},{100,-100,0} };
long float radians = 0.261799;

int rotCounter = 0;

int coordsSize = 4;

bool signTracker;



void printMatrix() {
	cout << endl << "-------------------------------------" << endl;
	for (int i = 0; i < coordsSize; i++) {
		cout << coords[i][0] << " ";
		cout << coords[i][1] << " ";
		cout << coords[i][2] << " ";
		cout << endl;
		cout << i << endl;
	}
	cout << endl << "-------------------------------------" << endl;
}


void drawStar() {

	glPointSize(10);
	glLineWidth(5);

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2i(coords[0][0], coords[0][1]);
	glColor3f(0, 1, 0);
	glVertex2i(coords[1][0], coords[1][1]);
	glColor3f(0, 0, 1);
	glVertex2i(coords[2][0], coords[2][1]);
	glColor3f(1, 1, 0);
	glVertex2i(coords[3][0], coords[3][1]);
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

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 1);			// specify a background clor: white 
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}



//***********************************************************************************





//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawStar();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void processTransX(int offset) {
	for (int i = 0; i < coordsSize; i++) {
		coords[i][0] += offset;
	}
	glutPostRedisplay();

	return;
}

void processTransY(int offset) {
	for (int i = 0; i < coordsSize; i++) {
		coords[i][1] += offset;
	}
	glutPostRedisplay();

	return;
}

void processRotate(int sign) {
	//x' = x cos f - y sin f
	//y' = y cos f + x sin f
	bool signFlag;
	printMatrix();
	for (int j = 0; j < coordsSize; j++) {
		float cosAngle, sinAngle;
		if (sign > 0) {
			signFlag = true;
			if (rotCounter < 0) {
				cosAngle = cos(radians * rotCounter); //0.96592582628;
				sinAngle = sin(radians * rotCounter); //0.2588190451;
			}
			else {
				cosAngle = cos(radians * rotCounter); //0.96592582628;
				sinAngle = sin(radians * rotCounter); //0.2588190451;
			}
		}
		else {
			signFlag = false;
			if (rotCounter < 0) {
				cosAngle = cos(radians * rotCounter); //0.96592582628;
				sinAngle = sin(radians * rotCounter) * -1; //0.2588190451;
			}
			else {
				cosAngle = cos(radians * rotCounter); //0.96592582628;
				sinAngle = sin(radians * rotCounter); //0.2588190451;
			}
		}

		coords[j][0] = (defaultCoords[j][0] * cosAngle - defaultCoords[j][1] * sinAngle);
		coords[j][1] = (defaultCoords[j][1] * cosAngle + defaultCoords[j][0] * sinAngle);
		cout << coords[j][0] << "  " << coords[j][1] << endl;
	}
	if (signFlag) {
		rotCounter++;
	}
	else {
		rotCounter--;
	}
	printMatrix();
	glutPostRedisplay();

	return;
}


void processMenu(int option) {
	 
	if (!option) {
		for (int i = 0; i < coordsSize; i++) {
			coords[i][0] = defaultCoords[i][0];
			coords[i][1] = defaultCoords[i][1];
			coords[i][2] = defaultCoords[i][2];
		}
		rotCounter = 0;
		glutPostRedisplay();
	}
	else if (option) {
		exit(0);
	}
	return;
}



void main()
{
	printMatrix();
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Hex Drawing");	// create a titled window

	int transXMenu = glutCreateMenu(processTransX);

	glutAddMenuEntry("-25", -25);
	glutAddMenuEntry("+25", 25);

	int transYMenu = glutCreateMenu(processTransY);

	glutAddMenuEntry("-25", -25);
	glutAddMenuEntry("+25", 25);

	int rotateMenu = glutCreateMenu(processRotate);

	glutAddMenuEntry("-15 Degrees", -1);
	glutAddMenuEntry("+15 Degrees", 1);

	int mainMenu = glutCreateMenu(processMenu);
	glutAddSubMenu("Translate X", transXMenu);
	glutAddSubMenu("Translate Y", transYMenu);
	glutAddSubMenu("Rotate", rotateMenu);
	glutAddMenuEntry("Reset Coordinates", 0);
	glutAddMenuEntry("Exit Program", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	myInit();									// setting up

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


