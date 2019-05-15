/*==================================================================================================
PROGRAMMER:				Yang Wang
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		09/09/2016
DESCRIPTION:			Demo: drawing lines from file input
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					DrawLines.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>
#include <GL/glut.h>				// include GLUT library
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string SELECTION;
std::vector<int> coords;
int loopIter = -1; //-1 to take care of an off by 1 error.




void menu(){
	cout << "Welcome to Trent Scotts line drawing program.\n";
	cout << "Please enter file name: ";

	cin >> SELECTION;
	return;

}


void drawLines() {
	string line;
	fstream myFile;
	myFile.open(("C:\\Temp\\" + SELECTION + ".txt"));

	if (myFile.is_open())
	{
		int a;
		int b;
		while (myFile >> a >> b) {
			coords.push_back(a);
			coords.push_back(b);
			loopIter++;
		}

		int h = 1;
		while (h <= loopIter) {

			int x1 = coords[h - 1];
			int y1 = coords[h];
			int x2 = coords[h + 1];
			int y2 = coords[h + 2];

			glColor3f(1, 0, 0);
			
			glBegin(GL_POINTS);
			glPointSize(10);
			bool draw = true;
	
			float x = x1;
			float y = y1;

			float dx = x2 - x1;
			float dy = y2 - y1;

			float slope = dy/dx;

			float intercept = y1 - slope * x1;

			if (x1 < x2) {
				for (float i = x1; i < x2; i += abs(slope)) {
					glVertex2f(x, y);
					cout << x << " " << y << endl;
					x += abs(slope);
					y = slope * x + intercept;
				}
			}
			else {
				for (float i = x1; i > x2; i -= abs(slope)) {
					glVertex2f(x, y);
					cout << x << " " << y << endl;
					x -= slope;
					y = slope * x + intercept;

				}
			}

			glEnd();
			h+=2;
		}


	}
	else {
		myFile.close();
		cout << "File " + SELECTION + " failed to open. ";
		cout << "Please try again. \n\n";
		menu();
	}


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
	glClearColor(1, 1, 1, 0);			// specify a background clor: white 
	gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawLines();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************


void main()
{
	glutInitWindowSize(400, 400);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Multiple Lines");	// create a titled window


	myInit();									// setting up

	menu();
	drawLines();

	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();							// get into an infinite loop
}


