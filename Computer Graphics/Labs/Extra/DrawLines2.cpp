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

std::vector<int> coords;
string SELECTION;
int numberOfPairs = 0;


void drawLines(){
	fstream myFile;
	myFile.open(("C:\\Temp\\" + SELECTION + ".txt"));

	if (myFile.is_open()){
		int a, b;
		while (myFile >> a >> b) {
			coords.push_back(a);
			coords.push_back(b);
			numberOfPairs++;
		}

		glPointSize(5);
		glColor3f(.6, 0, .5);
		glBegin(GL_POINTS);

		for (int i = 0; i < coords.size(); i+=2){
			glVertex2i(coords[i], coords[i+1]);
		}
		glEnd();

		glBegin(GL_POINTS);


		cout << "Coord pairs for drawing" << endl;
		for (int j = 0; j <= (coords.size()/2); j += 2){
			float x1 = coords[j];
			float y1 = coords[j + 1];
			float x2 = coords[j + 2];
			float y2 = coords[j + 3];

			cout << "\n\n-------------------------------------------\nIteration " << j << endl;
			

			cout << x1 << " " << y1 << endl;
			cout << x2 << " " << y2 << endl;

			float slope = (y2 - y1) / (x2 - x1);

			cout << "\n\nSlope: " << slope << "\n\n";


			float intercept = y1 - slope * x1;
			if (slope > 1){
				if (x1 < x2){
					for (float x = x1; x1 < x2; x1 -= slope){
						float y = slope * x1 + intercept;
						glVertex2f(x, y);
						cout << x << " " << y << endl;
					}
				}
				else {

					for (float x = x1; x > x2; x -= slope){
						float y = slope * x + intercept;
						glVertex2f(x, y);
						cout << x << " " << y << endl;
					}
				} 
				 
			}
			else if (slope < 1) {
				if (x1 < x2){

					for (float x = x1; x < x2; x -= slope){
						float y = slope * x + intercept;
						glVertex2f(x, y);
						cout << x << " " << y << endl;
					}
				}
				else {

					for (float x = x1; x > x2; x += slope){
						float y = slope * x + intercept;
						glVertex2f(x, y);
						cout << x << " " << y << endl;
					}
				}

			}


		}
		glEnd();

		glPointSize(1);		// change point size back to 1

		glColor3f(0, 0, 0);
		glBegin(GL_POINTS);	// use points to form X-/Y-axes
		for (int x = -150; x <= 150; x++) // draw X-axis
			glVertex2i(x, 0);
		for (int y = -150; y <= 150; y++) // draw Y-axis
			glVertex2i(0, y);




		glEnd();
	}
	else {
		cout << "You suck Trenton. Get your shit together. ";
	
	}


	return;



}


void menu() {
	cout << "Welcome to Trent Scotts line drawing program.\n";
	cout << "Please enter file name: ";

	cin >> SELECTION;
	drawLines();
	return;

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
	menu();
	myInit();									// setting up


	glutDisplayFunc(myDisplayCallback);		// register a callback

	glutMainLoop();

}
