/*==================================================================================================
PROGRAMMER:				Sam Faulkner and Trent Scott
COURSE:					CSC 525/625
MODIFIED BY:			Sam Faulkner and Trent Scott
TRACE FOLDERS:			Faulkner726 and Scott031
CONTRIBUTIONS:			Sam - 50%					||			Trent - 50%
- Invisible 3D Cube Logos are on	||		-Rotation
- 2D Polygons for Logo				||		-Text Placement on poster
- 3D Desk Logo is on				||		-Walls and Floors

LAST MODIFIED DATE:		12/11/2016
DESCRIPTION:			Adverstisement for Computer Services Help Desk
NOTE:					Logo taken from Computer Information Systems department at Missouri State University
FILES:					CSHD_Ad.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <stdlib.h>
#include <GL/glut.h>
#include <string>

using namespace std;

// Colors for Computer Information Services Logo
const GLfloat WHITE[3] = { 1, 1, 1 };
const GLfloat MAROON[3] = { 0.357, 0.0314, 0.0627 };
const GLfloat DENIM[3] = { 0.0667, 0.408, 0.686 };
const GLfloat AKAROA[3] = { 0.733, 0.675, 0.6 };
const GLfloat BUTTERCUP[3] = { 0.867, 0.576, 0.235 };
const GLfloat ONAHAU[3] = { 0.808, 0.875, 0.945 };
const GLfloat WASABI[3] = { 0.475, 0.561, 0.235 };



// Color for Desk
const GLfloat BLACK[3] = { 0, 0, 0 };
const GLfloat MAHOGANY[3] = { 0.804, 0.522, 0.247 };
const GLfloat SIENNA[3] = { 0.627, 0.322, 0.176 };
const GLfloat BROWN[3] = { 0.545, 0.271, 0.0745 };
const GLfloat BLUEISH[3] = { 0, 0.9, 0.9 };


//color for wall

const GLfloat STONE[3] = { 0.3529, 0.30196, 0.2549 };
const GLfloat ROYAL[3] = { 0.2549, 0.41176, 0.88235 };

// Vertices for Rotating Cube
int cube[][3] =
{
	-50, 50,  0,
	-50, 50,  100, //1
	50, 50,  100, //2
	50, 50,  0,
	-50, 150, 0,
	-50, 150, 100, //5
	50, 150, 100, //6
	50, 150, 0
};

long int FLOOROFOFFICE = 1000;

// Vertices floor
int floorOfOffice[][3] =
{
	-FLOOROFOFFICE, FLOOROFOFFICE - 500, -FLOOROFOFFICE,
	-FLOOROFOFFICE, FLOOROFOFFICE - 500, FLOOROFOFFICE,
	FLOOROFOFFICE, FLOOROFOFFICE - 500, FLOOROFOFFICE,
	FLOOROFOFFICE, FLOOROFOFFICE - 500, -FLOOROFOFFICE
};


// Vertices for back wall

int backOfOffice[][3] =
{
	-1000, 1000 ,  -150 , //1
	1000, 1000,  -150, //2
	1000, -1000, -150, //6
	-1000, -1000, -150, //5
};


int poster[][3] =
{
	-200, 250 ,  -149 , //1
	200, 250,  -149, //2
	200, 50, -149, //6
	-200, 50, -149, //5
};


// Vertices for logo on side 1
int logo1[][3] =
{
	// Maroon Box
	8, 144, 101,	// v0
	50, 144, 101,	// v1
	50,  57, 101,	// v2
	8,  57, 101,	// v3
					// Denim Box
					4, 144, 101,	// v4
					-50, 144, 101,	// v5
					-50, 129, 101,	// v6
					4, 129, 101,	// v7
									// Akaroa Box
									4, 126, 101,	// v8
									-50, 126, 101,	// v9
									-50, 111, 101,	// v10
									4, 111, 101,	// v11
													// Buttercup Box
													4, 108, 101,	// v12
													-50, 108, 101,	// v13
													-50, 93, 101,	// v14
													4, 93, 101,	// v15
																// Onahau Box
																4, 90, 101,	// v16
																-50, 90, 101,	// v17
																-50, 75, 101,	// v18
																4, 75, 101,	// v19
																			// Wasabi Box
																			4, 72, 101,	// v20
																			-50, 72, 101,	// v21
																			-50,  57, 101,	// v22
																			4,  57, 101	// v23
};

// Vertices for logo on side 2
int logo2[][3] =
{
	// Maroon Box
	51, 144, 0,	    // v0
	51, 144, 42,	// v1
	51,  57, 42,	// v2
	51,  57, 0,		// v3
					// Denim Box
					51, 144, 46,	// v4
					51, 144, 100,	// v5
					51, 129, 100,	// v6
					51, 129, 46,	// v7
									// Akaroa Box
									51, 126, 46,	// v8
									51, 126, 100,	// v9
									51, 111, 100,	// v10
									51, 111, 46,	// v11
													// Buttercup Box
													51, 108, 46,	// v12
													51, 108, 100,	// v13
													51,  93, 100,	// v14
													51,  93, 46,	// v15
																	// Onahau Box
																	51, 90, 46,		// v16
																	51, 90, 100,	// v17
																	51, 75, 100,	// v18
																	51, 75, 46,		// v19
																					// Wasabi Box
																					51, 72,  46,	// v20
																					51, 72, 100,	// v21
																					51, 57, 100,	// v22
																					51, 57,  46		// v23
};

// Vertices for logo on side 3
int logo3[][3] =
{
	// Maroon Box
	-8, 144, -1,	// v0
	-50, 144, -1,	// v1
	-50, 57,  -1,	// v2
	-8, 57,  -1,	// v3
					// Denim Box
					50, 144, -1,	// v4
					-4, 144, -1,	// v5
					-4, 129, -1,	// v6
					50, 129, -1,	// v7
									// Akaroa Box
									50, 126, -1,	// v8
									-4, 126, -1,	// v9
									-4, 111, -1,	// v10
									50, 111, -1,	// v11
													// Buttercup Box
													50, 108, -1,	// v12
													-4, 108, -1,	// v13
													-4, 93, -1,	// v14
													50, 93, -1,	// v15
																// Onahau Box
																50, 90, -1,	// v16
																-4, 90, -1,	// v17
																-4, 75, -1,	// v18
																50, 75, -1,	// v19
																			// Wasabi Box
																			50, 72, -1,	// v20
																			-4, 72, -1,	// v21
																			-4, 57, -1,	// v22
																			50, 57, -1		// v23
};

// Vertices for logo on side 4
int logo4[][3] =
{
	// Maroon Box
	-51, 144, 100,	// v0
	-51, 144, 58,	// v1
	-51,  57, 58,	// v2
	-51,  57, 100,	// v3
					// Denim Box
					-51, 144, 54,	// v4
					-51, 144, 0,	// v5
					-51, 129, 0,	// v6
					-51, 129, 54,	// v7
									// Akaroa Box
									-51, 126, 54,	// v8
									-51, 126, 0,	// v9
									-51, 111, 0,	// v10
									-51, 111, 54,	// v11
													// Buttercup Box
													-51, 108, 54,	// v12
													-51, 108, 0,	// v13
													-51, 93, 0,		// v14
													-51, 93, 54,	// v15
																	// Onahau Box
																	-51, 90, 54,	// v16
																	-51, 90, 0,		// v17
																	-51, 75, 0,		// v18
																	-51, 75, 54,	// v19
																					// Wasabi Box
																					-51, 72, 54,	// v20
																					-51, 72, 0,		// v21
																					-51, 57, 0,		// v22
																					-51, 57, 54		// v23
};
// Vertices for desk
int desk[][3] =
{
	-150,  50, -25,		// desk[0]
	150,  50, -25,		// desk[1]
	150,  50,  125,	// desk[2]
	-150,  50,  125,	// desk[3]
	-150, -100,-25,		// desk[4]
	-150, -100, 125,	// desk[5]
	150, -100, 125,	// desk[6]
	150, -100,-25,		// desk[7]
	50,  50, -25,		// desk[8]
	50, -100,-25,		// desk[9]
	-50,  50, -25,		// desk[10]
	-50, -100,-25,		// desk[11]
	-50,  25, -25,		// desk[12]
	50,  25, -25,		// desk[13]
	50,  25,  100,	// desk[14]
	50, -100, 100,	// desk[15]
	-50,  25,  100,	// desk[16]
	-50, -100, 100,	// desk[17]
	50, -100, 125,	// desk[18]
	-50, -100, 125		// desk[19]
};

int angleX = 0;
int angleY = 0;
int angleZ = 0;

//***********************************************************************************
void drawSide(bool filled, const GLfloat color[], int v1[], int v2[], int v3[], int v4[])
// This function creates one side of a polygon based on the color and the 4 vertices that make up the square
{
	GLenum fill;
	if (filled == true)
		fill = GL_FILL;
	else
		fill = GL_LINE;

	glPolygonMode(GL_FRONT, fill);		// The front face is solid
	glPolygonMode(GL_BACK, fill);		// The back face is empty
	glBegin(GL_POLYGON);
	glColor3fv(color);
	glVertex3iv(v1);
	glVertex3iv(v2);
	glVertex3iv(v3);
	glVertex3iv(v4);
	glEnd();
}

//***********************************************************************************
void drawCube()
{
	drawSide(true, BLACK, cube[0], cube[1], cube[2], cube[3]);
	drawSide(true, BLACK, cube[0], cube[1], cube[5], cube[4]);
	drawSide(true, BLACK, cube[1], cube[2], cube[6], cube[5]); //forward face
	drawSide(true, BLACK, cube[2], cube[3], cube[7], cube[6]);
	drawSide(true, BLACK, cube[3], cube[0], cube[4], cube[7]);
	drawSide(true, BLACK, cube[4], cube[5], cube[6], cube[7]); //top face
}

//***********************************************************************************
void drawLogo()
{
	// Side 1
	drawSide(true, MAROON, logo1[0], logo1[1], logo1[2], logo1[3]);
	drawSide(true, DENIM, logo1[4], logo1[5], logo1[6], logo1[7]);
	drawSide(true, AKAROA, logo1[8], logo1[9], logo1[10], logo1[11]);
	drawSide(true, BUTTERCUP, logo1[12], logo1[13], logo1[14], logo1[15]);
	drawSide(true, ONAHAU, logo1[16], logo1[17], logo1[18], logo1[19]);
	drawSide(true, WASABI, logo1[20], logo1[21], logo1[22], logo1[23]);

	// Side 2
	drawSide(true, MAROON, logo2[0], logo2[1], logo2[2], logo2[3]);
	drawSide(true, DENIM, logo2[4], logo2[5], logo2[6], logo2[7]);
	drawSide(true, AKAROA, logo2[8], logo2[9], logo2[10], logo2[11]);
	drawSide(true, BUTTERCUP, logo2[12], logo2[13], logo2[14], logo2[15]);
	drawSide(true, ONAHAU, logo2[16], logo2[17], logo2[18], logo2[19]);
	drawSide(true, WASABI, logo2[20], logo2[21], logo2[22], logo2[23]);

	// Side 3
	drawSide(true, MAROON, logo3[0], logo3[1], logo3[2], logo3[3]);
	drawSide(true, DENIM, logo3[4], logo3[5], logo3[6], logo3[7]);
	drawSide(true, AKAROA, logo3[8], logo3[9], logo3[10], logo3[11]);
	drawSide(true, BUTTERCUP, logo3[12], logo3[13], logo3[14], logo3[15]);
	drawSide(true, ONAHAU, logo3[16], logo3[17], logo3[18], logo3[19]);
	drawSide(true, WASABI, logo3[20], logo3[21], logo3[22], logo3[23]);

	// Side 4
	drawSide(true, MAROON, logo4[0], logo4[1], logo4[2], logo4[3]);
	drawSide(true, DENIM, logo4[4], logo4[5], logo4[6], logo4[7]);
	drawSide(true, AKAROA, logo4[8], logo4[9], logo4[10], logo4[11]);
	drawSide(true, BUTTERCUP, logo4[12], logo4[13], logo4[14], logo4[15]);
	drawSide(true, ONAHAU, logo4[16], logo4[17], logo4[18], logo4[19]);
	drawSide(true, WASABI, logo4[20], logo4[21], logo4[22], logo4[23]);
}

//***********************************************************************************
void drawDesk()
{
	// Outlines Desk in Black
	drawSide(false, BLACK, desk[0], desk[1], desk[2], desk[3]);
	drawSide(false, BLACK, desk[0], desk[3], desk[5], desk[4]);
	drawSide(false, BLACK, desk[3], desk[2], desk[6], desk[5]);
	drawSide(false, BLACK, desk[2], desk[1], desk[7], desk[6]);
	drawSide(false, BLACK, desk[1], desk[8], desk[9], desk[7]);
	drawSide(false, BLACK, desk[10], desk[0], desk[4], desk[11]);
	drawSide(false, BLACK, desk[8], desk[10], desk[12], desk[13]);
	drawSide(false, BLACK, desk[13], desk[14], desk[15], desk[9]);
	drawSide(false, BLACK, desk[16], desk[12], desk[11], desk[17]);
	drawSide(false, BLACK, desk[14], desk[16], desk[17], desk[15]);
	drawSide(false, BLACK, desk[14], desk[16], desk[12], desk[13]);
	drawSide(false, BLACK, desk[18], desk[6], desk[7], desk[9]);
	drawSide(false, BLACK, desk[5], desk[19], desk[11], desk[4]);
	drawSide(false, BLACK, desk[19], desk[18], desk[15], desk[17]);

	// Fills in Desk in Brown Colors
	drawSide(true, MAHOGANY, desk[0], desk[1], desk[2], desk[3]);
	drawSide(true, MAHOGANY, desk[0], desk[3], desk[5], desk[4]);
	drawSide(true, MAHOGANY, desk[3], desk[2], desk[6], desk[5]);
	drawSide(true, MAHOGANY, desk[2], desk[1], desk[7], desk[6]);
	drawSide(true, MAHOGANY, desk[1], desk[8], desk[9], desk[7]);
	drawSide(true, MAHOGANY, desk[10], desk[0], desk[4], desk[11]);
	drawSide(true, MAHOGANY, desk[8], desk[10], desk[12], desk[13]);
	drawSide(true, SIENNA, desk[13], desk[14], desk[15], desk[9]);
	drawSide(true, SIENNA, desk[16], desk[12], desk[11], desk[17]);
	drawSide(true, BROWN, desk[14], desk[16], desk[17], desk[15]);
	drawSide(true, SIENNA, desk[14], desk[16], desk[12], desk[13]);
	drawSide(true, MAHOGANY, desk[18], desk[6], desk[7], desk[9]);
	drawSide(true, MAHOGANY, desk[5], desk[19], desk[11], desk[4]);
	drawSide(true, MAHOGANY, desk[19], desk[18], desk[15], desk[17]);
}

//***********************************************************************************
void drawText(string text, const GLfloat color[], int x, int y, int z)
{
	glColor3fv(color);
	glRasterPos3i(x, y, z);
	for (size_t i = 0; i < text.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}
}

//***********************************************************************************
void rotateXsub(int option)
{
	switch (option)
	{
	case 0:
		angleX += 1;		// Increases the rotation angle of the x-axis by 45 degrees
		break;
	case 1:
		angleX -= 1;		// Decreases the rotation angle of the x-axis by 45 degrees
		break;
	}

	glutPostRedisplay();
}

//***********************************************************************************
void rotateYsub(int option)
{
	switch (option)
	{
	case 0:
		angleY += 1;		// Increases the rotation angle of the y-axis by 45 degrees
		break;
	case 1:
		angleY -= 1;		// Decreases the rotation angle of the y-axis by 45 degrees
		break;
	}

	glutPostRedisplay();
}

//***********************************************************************************
void rotateZsub(int option)
{
	switch (option)
	{
	case 0:
		angleZ += 1;		// Increases the rotation angle of the z-axis by 45 degrees
		break;
	case 1:
		angleZ -= 1;		// Decreases the rotation angle of the z-axis by 45 degrees
		break;
	}

	glutPostRedisplay();
}
float g_RotateX = 0.0f;
float g_RotateY = 0.0f;
float g_RotateZ = 0.0f;
float g_RotationSpeed = 0.1f;
//***********************************************************************************
void RenderScene()
{
	
	glPushMatrix();					// Pushing the matrix ignores everything already in the window

	gluLookAt(0.0, 0.09, 5.0, 0.0, -0.1, 4.2, 0.0, 1.0, 4.0);

	glTranslatef(0, 100, 0);

	glRotatef(angleX, 1, 0, 0);		// Rotate the x-axis
	glRotatef(angleY, 0, 1, 0);		// Rotate the y-axis
	glRotatef(angleZ, 0, 0, 1);		// Rotate the z-axis
	glTranslatef(0, -100, 0);

	drawCube();						// Renders the Invisible Cube
	drawLogo();						// Renders the Logos on the 4 sides of the cube
	drawDesk();
	drawSide(true, ROYAL, backOfOffice[0], backOfOffice[1], backOfOffice[2], backOfOffice[3]); //forward face
	drawSide(true, WHITE, poster[0], poster[1], poster[2], poster[3]); //draw poster
	string welcome = "Welcome to Computer Services.$We offer all kinds of services like...$";
	welcome += "-Open Acess Computers$-Computer and User Account Support$-Sound-proof Multimedia Rooms";
	welcome += "$Stop by Cheek, Glass, or the Library$and we would be happy to help you.";
	glColor3f(0, 0, 0);
	
	int rasterY = 235;
	int rasterXCounter = 0;
	for (int i = 0; i < welcome.length(); i++) {
		glRasterPos3i(-195 + rasterXCounter * 10, rasterY, -146);
		if (welcome[i] == *"$") {
			rasterY -= 19;
			rasterXCounter = 0;
			continue;
		}
		else {
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, welcome[i]);
		}
		rasterXCounter++;
	}


	glDisable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_TEST);
	glTranslatef(0, -600, 0);
	drawSide(true, STONE, floorOfOffice[0], floorOfOffice[1], floorOfOffice[2], floorOfOffice[3]); //floor of office
	glTranslatef(0, 600, 0);
	glPopMatrix();					// Popping this matrix allows the next rotation to only effect the object instead of everythin
}

//***********************************************************************************
void reset()
// Sets the object back to its original orientation
/// The RenderScene() function is in each loop in case only one axis is rotated.
{
	while (angleX != 0)
	{
		angleX = -angleX;		// Setting the angle to its reciprocal undoes all the rotation to that axis
		RenderScene();
		angleX = 0;				// Sets the angle back to 0
	}

	while (angleY != 0)
	{
		angleY = -angleY;		// Setting the angle to its reciprocal undoes all the rotation to that axis
		RenderScene();
		angleY = 0;				// Sets the angle back to 0
	}

	while (angleZ != 0)
	{
		angleZ = -angleZ;		// Setting the angle to its reciprocal undoes all the rotation to that axis
		RenderScene();
		angleZ = 0;				// Sets the angle back to 0
	}
}

//***********************************************************************************
void menu(int option)
{
	switch (option)
	{
	case 0:
		reset();
		break;
	case 1:
		exit(0);
	}

	glutPostRedisplay();
}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);					// specify a background color: white 
	glOrtho(-300, 300, -300, 300, -1000, 1000);	// specify a viewing area
	glEnable(GL_DEPTH_TEST);
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// draw the background
	RenderScene();
	glFlush(); // flush out the buffer contents
}

void specialFunc(int key, int x, int y) {
	if (key == 100) rotateZsub(0);
	else if (key == 102)  rotateZsub(1);
	else if (key == 101) rotateYsub(1);
	else if (key == 103) rotateYsub(0);

}

//***********************************************************************************
void main()
{
	glutInitWindowSize(500, 500);				// specify a window size
	glutInitWindowPosition(0, 0);				// specify a window position
	glutCreateWindow("PROJECT");				// create a titled window
	myInit();									// setting up
	glutDisplayFunc(myDisplayCallback);			// register a callback


	int rotateX = glutCreateMenu(rotateXsub);	// set up x-axis submenu
	glutAddMenuEntry("+45 Degrees", 0);
	glutAddMenuEntry("-45 Degrees", 1);

	int rotateY = glutCreateMenu(rotateYsub);	// set up y-axis submenu
	glutAddMenuEntry("+45 Degrees", 0);
	glutAddMenuEntry("-45 Degrees", 1);

	int rotateZ = glutCreateMenu(rotateZsub);	// set up z-axis submenu
	glutAddMenuEntry("+45 Degrees", 0);
	glutAddMenuEntry("-45 Degrees", 1);

	int mainMenu = glutCreateMenu(menu);		// set up entire menu
	glutAddSubMenu("Rotate X-Axis", rotateX);
	glutAddSubMenu("Rotate Y-Axis", rotateY);
	glutAddSubMenu("Rotate Z-Axis", rotateZ);
	glutAddMenuEntry("Reset Vertices", 0);
	glutAddMenuEntry("Exit Program", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);			// menu appears on right click

	glutSpecialFunc(specialFunc);

	glutMainLoop();								// get into an infinite loop
}