/*==================================================================================================
PROGRAMMER:			Yang Wang
COURSE:				CSC 525/625
MODIFIED BY:		Samuel Faulkner, Trenton Scott
LAST MODIFIED DATE:	10/14/2016
DESCRIPTION:			Project: 2D Drawing and Animation
NOTE:					N/A
FILES:					Space.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <iostream>					// allows reading and writing streams
#include <GL/glut.h>				// include GLUT library
#include <string>					// includes string datatype
#include <fstream>					// allows use of ifstream statements
using namespace std;

//***********************************************************************************
// predefined colors for later use
GLfloat RED[3] = { 1, 0, 0 };
GLfloat GREEN[3] = { 0, 1, 0 };
GLfloat BLUE[3] = { 0, 0, 1 };
GLfloat BLACK[3] = { 0, 0, 0 };
GLfloat WHITE[3] = { 1, 1, 1 };
GLfloat GRAY[3] = { 0.2, 0.2, 0.2 };
GLfloat YELLOW[3] = { 1, 1, 0 };
GLfloat MAGENTA[3] = { 1, 0, 1 };
GLfloat CYAN[3] = { 0, 1, 1 };

//***********************************************************************************
//	GLOBAL VARIABLES	//
float MAP[512][512][3];
float SCREENSHOT[512][512][3];

// variables for animation //
float asteroidOffsetX = 0.0; //asteroid offset of x
float asteroidOffsetY = 0.0; //asteroid offset of y
float asteroidDelta = 0.005; //animation speed. Closer to 1 is faster. 
int asteroidSwitch = 0; //switch to change the direction of the asteroid
float ufoAnimOffset;
bool ufoAnimSwitch = false; //tells which way the UFO is going. 

//***********************************************************************************
void createBackground()
{
	// Reads RGB values from text file, and stores them in a pixelmap

	ifstream myFile;
	myFile.open("\\\\trace\\Class\\CSC-525-625\\001\\Faulkner726\\projects\\proj1\\background.txt");	// open text file from TRACE folder

	float r, g, b;			// create variables for each color
	int height = 0;			// create variable for height and width
	int width = 0;

	while (myFile >> r >> g >> b) {			// loop through the file...
		MAP[height][width][0] = r / 255;		// ...first number is red value...
		MAP[height][width][1] = g / 255;		// ...second number is green value...
		MAP[height][width][2] = b / 255;		// ...third number is blue value.
		width++;							// moves to the right one pixel after reading RGB values

		if (width >= 512) {		// once the width gets to the end of the picture,...
			width = 0;			// ...reset the width...
			height++;			// ...move up one row...
		}
	}

	myFile.close();		// close the file
}

//***********************************************************************************
void background()
{
	/* Prints out the background onto the viewing window in a 512 x 512 frame */

	glRasterPos2i(-256, -256);
	glDrawPixels(512, 512, GL_RGB, GL_FLOAT, MAP);
}

//***********************************************************************************
void score()
{
	/* Prints the text at the top of the screen */

	string Score = "The alien watched from the comfort of his force field as his UFO lost control";		// bitmap text

	int center = 0;
	for (size_t i = 0; i < Score.length(); i++)			// loops through string getting width of each character in pixels
	{
		center += glutBitmapWidth(GLUT_BITMAP_HELVETICA_12, Score[i]);
	}

	glColor3fv(WHITE);							// text will be white
	glRasterPos2i(0 - center / 2, 200);				// text centered horizontally
	for (size_t i = 0; i < Score.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, Score[i]);
	}

}

//***********************************************************************************
void ufo()
{
	/* Creates a UFO made from line segments */
	glPointSize(1);		// set vertex size to 1
	glLineWidth(1);		// set line width to being 1
	glColor3fv(WHITE);	// display UFO as white

	if (ufoAnimSwitch){
		ufoAnimOffset -= .04;
		if (ufoAnimOffset < -80){
			ufoAnimSwitch = false;
		}
	}
	else if (!ufoAnimSwitch){
		ufoAnimOffset += .04;
		if (ufoAnimOffset > 30){
			ufoAnimSwitch = true;
		}
	}

	glBegin(GL_LINE_LOOP);		// draw the body of the UFO
	glVertex2i(110 + ufoAnimOffset, 80);
	glVertex2i(115 + ufoAnimOffset, 70);
	glVertex2i(130 + ufoAnimOffset, 60);
	glVertex2i(117 + ufoAnimOffset, 50);
	glVertex2i(93 + ufoAnimOffset, 50);
	glVertex2i(80 + ufoAnimOffset, 60);
	glVertex2i(95 + ufoAnimOffset, 70);
	glVertex2i(100 + ufoAnimOffset, 80);
	glEnd();

	glBegin(GL_LINE_STRIP);		// connect the capsule to the UFO
	glVertex2i(115 + ufoAnimOffset, 70);
	glVertex2i(95 + ufoAnimOffset, 70);
	glEnd();

	glBegin(GL_LINE_STRIP);		// illustrate the edge of the UFO
	glVertex2i(130 + ufoAnimOffset, 60);
	glVertex2i(80 + ufoAnimOffset, 60);
	glEnd();
}

//***********************************************************************************
void alien()
{
	/* Creates a bitmap of an alien to display */
	GLubyte pattern[] = {
		0x00, 0x3f, 0x00, 0x1f,
		0x00, 0x7f, 0xe0, 0x7f,
		0x00, 0x7f, 0xfb, 0xff,
		0x00, 0x3f, 0xff, 0xff,
		0x00, 0x1f, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xe0,
		0x00, 0x00, 0x3f, 0xc0,
		0x00, 0x00, 0x3f, 0xc0,
		0x00, 0x00, 0x3f, 0xc0,
		0x00, 0x00, 0x3f, 0xc0,
		0x00, 0x00, 0x3f, 0xe0,
		0x00, 0x00, 0x3f, 0xe0,
		0x00, 0x00, 0x3f, 0xe0,
		0x00, 0x00, 0x7f, 0xe0,
		0x00, 0x00, 0x7f, 0xe0, //alien hex code
		0x00, 0x00, 0x7f, 0xe0,
		0x00, 0x00, 0x7f, 0xe0,
		0x00, 0x00, 0x7f, 0xf0,
		0x00, 0x00, 0xff, 0xf0,
		0x00, 0x00, 0xff, 0xf8,
		0x00, 0x00, 0xff, 0xf8,
		0x00, 0x00, 0xff, 0xfc,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfe,
		0x00, 0x00, 0xff, 0xfe,
		0x00, 0x00, 0xff, 0xfe,
		0x00, 0x01, 0xff, 0xfc,
		0x00, 0x07, 0xff, 0xf8,
		0x00, 0x3f, 0xff, 0xf0,
		0x00, 0x7f, 0xff, 0x80,
		0x00, 0xf0, 0x1f, 0x00,
		0x01, 0xe0, 0x0e, 0x00,
		0x01, 0xc0, 0x1f, 0x00,
		0x03, 0x80, 0x3f, 0x80,
		0x03, 0x80, 0x7f, 0xc0,
		0x00, 0x00, 0x7f, 0xe0,
		0x07, 0x01, 0xff, 0xf0,
		0x1e, 0x03, 0xff, 0xf8,
		0x3e, 0x07, 0xff, 0xfc,
		0x7e, 0x07, 0xde, 0x7c,
		0x7f, 0x0f, 0x1e, 0x1e,
		0x3f, 0x0e, 0x1e, 0x0e,
		0x1e, 0x1c, 0x1f, 0x06,
		0x1e, 0x18, 0x1f, 0x03,
		0x16, 0x18, 0x1f, 0x83,
		0x36, 0x10, 0x3f, 0x81,
		0x76, 0x10, 0xff, 0xc1,
		0x66, 0x09, 0xff, 0xfe,
		0x46, 0x1f, 0xff, 0xff,
		0x00, 0x1f, 0xff, 0xff,
		0x00, 0x0f, 0xff, 0xfe,
		0x00, 0x0f, 0xff, 0xfe,
		0x00, 0x07, 0xFF, 0xFC,
		0x00, 0x07, 0xFF, 0xFC,
		0x00, 0x03, 0xFF, 0xF8,
		0x00, 0x00, 0xff, 0xe0,
		0x00, 0x00, 0x3F, 0xC0,
	};

	glColor3fv(CYAN);
	glRasterPos2i(0, -150);
	glBitmap(32, 63, 0, 0, 0, 0, pattern);
}

//***********************************************************************************
void forceField()
{
	/* Creates a force field around the alien */
	glPointSize(1);

	for (int i = 0; i <= 1000; i++)
	{
		glBegin(GL_POINTS);
		float x = (cos((2 * i*3.14) / 300)) * 50;
		float y = (sin((2 * i*3.14) / 300)) * 50; //draw the circle around the alien
		glVertex2i(x + 20, y - 122);
		glEnd();
	}

	glutPostRedisplay();

}

//***********************************************************************************
void asteroid()
{
	/* Creates an asteroid with a stipple pattern */

	glEnable(GL_POLYGON_STIPPLE);
	GLenum mode = GL_FILL;

	GLubyte asteroid[] = {
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, //simple stipple pattern for asteroid
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
		0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	};

	if (asteroidSwitch == 0) {		//switch is used to turn the direction of x and y
		asteroidOffsetX += asteroidDelta;
		asteroidOffsetY += asteroidDelta;
		if (asteroidOffsetX > 5.0) asteroidSwitch = 1;	//this is where the animation magic happens
	}
	else if (asteroidSwitch == 1) {
		asteroidOffsetX -= asteroidDelta;
		if (asteroidOffsetX < -5.0) asteroidSwitch = 2;
	}
	else if (asteroidSwitch == 2) {
		asteroidOffsetX += asteroidDelta;
		asteroidOffsetY -= asteroidDelta;
		if (asteroidOffsetX > 5.0) asteroidSwitch = 3;
	}
	else if (asteroidSwitch == 3) {
		asteroidOffsetY += asteroidDelta;
		if (asteroidOffsetY > asteroidDelta) asteroidSwitch = 0;
	}


	glPolygonStipple(asteroid);

	glPointSize(10);
	glLineWidth(5);
	glColor3fv(GRAY); //color of an asteroid
	glPolygonMode(GL_FRONT, mode);
	glBegin(GL_POLYGON);
	glVertex3f(-150 + asteroidOffsetX, 160 + asteroidOffsetY, 0.0); //this is how to animation works
	glVertex3f(-220 + asteroidOffsetX, 140 + asteroidOffsetY, 0.0);
	glVertex3f(-180 + asteroidOffsetX, 40 + asteroidOffsetY, 0.0);
	glVertex3f(-120 + asteroidOffsetX, 40 + asteroidOffsetY, 0.0);
	glVertex3f(-80 + asteroidOffsetX, 110 + asteroidOffsetY, 0.0);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
}

//***************************************************************************
void takeScreenshot()
{
	/* Stores pixels in the 512 x 512 area of the viewing window */

	glReadPixels(44, 44, 512, 512, GL_RGB, GL_FLOAT, &SCREENSHOT);

	ofstream myFile("C:\\TEMP\\savedImg.txt");
	if (myFile.is_open())
	{
		for (int i = 0; i < 512; i++)
		{
			for (int j = 0; j < 512; j++)
			{
				myFile << SCREENSHOT[i][j][0] << " "
					<< SCREENSHOT[i][j][1] << " "
					<< SCREENSHOT[i][j][2] << " ";
			}
		}

		myFile.close();
	}

	glutPostRedisplay();
}


//***********************************************************************************
void keyboardInput(unsigned char key, int x, int y)
{
	if (key == 13)
	{
		takeScreenshot();	// captures screenshot after pressing the enter key
	}
	glutPostRedisplay();
}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background color: white 
	gluOrtho2D(-300, 300, -300, 300);	// specify a viewing area
}

//***********************************************************************************
void display()
{
	background();
	score();
	ufo();
	alien();
	forceField();
	asteroid();
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	display();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);				// specify a window size
	glutInitWindowPosition(100, 0);				// specify a window position
	glutCreateWindow("2D Rendering");			// create a titled window

	myInit();									// setting up

	createBackground();							// loads the background from the text file

	glutDisplayFunc(myDisplayCallback);			// register a callback

	glutKeyboardFunc(keyboardInput);

	glutMainLoop();								// get into an infinite loop
}
