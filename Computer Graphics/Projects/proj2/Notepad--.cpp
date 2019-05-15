/*==================================================================================================
PROGRAMMER:				Sam Faulkner and Trent Scott
COURSE:					CSC 525/625
MODIFIED BY:			Sam Faulkner and Trent Scott
CONTRIBUTIONS:			Sam:
							Font (Color and Style)
							Help Window (Display and Function)
							Menu
						Trent: 
							Typing Functionality
							Click Functionality
							Save File

LAST MODIFIED DATE:		11/11/2016
DESCRIPTION:			Demo: Text Editing Application
NOTE:					Program adopted from Dr. Wang for assignment completion purposes.
FILES:					Notepad--.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>			// Using cout and cin statements
#include <stdio.h>			// Standard I/O
#include <GL/glut.h>		// Glut library
#include <string>			// Allow use of string
#include <vector>			// Allow use of vector
#include <fstream>			//for write to file
using namespace std;

////////// Global Color Arrays //////////
GLfloat RED[3] = { 1, 0, 0 };
GLfloat ORANGE[3] = { 1, 0.647, 0 };
GLfloat YELLOW[3] = { 1, 1, 0 };
GLfloat GREEN[3] = { 0, 1, 0 };
GLfloat CYAN[3] = { 0, 1, 1 };
GLfloat BLUE[3] = { 0, 0, 1 };
GLfloat MAGENTA[3] = { 1, 0, 1 };
GLfloat BLACK[3] = { 0, 0, 0 };
GLfloat WHITE[3] = { 1, 1, 1 };
/////////////////////////////////////////

////////// Global Variables //////////
GLfloat * COLOR = BLACK;
vector <string> INPUT = { "" };
void * FONT = GLUT_BITMAP_HELVETICA_12;
int LINE_HEIGHT = 12;
int LINE_NUMBER = 0;
int EDITOR_WINDOW_ID;
int INFO_WINDOW_ID;
bool COLOR_FLAG = false;


//***********************************************************************************
void typingText()
{
	glPointSize(1);		// change point size back to 1
	glColor3fv(COLOR);

	if ((INPUT[LINE_NUMBER].length() % 50 == 0 && INPUT[LINE_NUMBER].length() != 0) || LINE_NUMBER == 0) 
	{
		//if statement characters in line does not = 0; each line is 50 characters, or line number is 0;
		LINE_NUMBER++;
		INPUT.push_back("");
	}

	for (size_t h = 0; h <= INPUT.size() - 1; h++)
	{
		glRasterPos2i(0, 600 - (LINE_HEIGHT * h));
		for (size_t i = 0; i < INPUT[h].length(); i++)
		{
			glutBitmapCharacter(FONT, INPUT[h][i]);
		}
	}
}

//***********************************************************************************
void type(unsigned char key, int x, int y)
{
	if (key == 13)
	{
		LINE_NUMBER++;
		INPUT.push_back("");
	}
	else if (key == 8 || key == 127)
	{
		if (INPUT[LINE_NUMBER].length() == 0 && LINE_NUMBER != 1)
		{
			LINE_NUMBER--;
			INPUT.pop_back();
		}
		else if (INPUT[LINE_NUMBER].length() == 0 && LINE_NUMBER == 1)
		{
			cout << "\a";
		}
		else
		{
			INPUT[LINE_NUMBER] = INPUT[LINE_NUMBER].substr(0, INPUT[LINE_NUMBER].length() - 1);
			//if none of the other conditions are met, 
			//then pop the last char and continue. 
		}
	}
	else
	{
		INPUT[LINE_NUMBER] += key;
	}
	glutPostRedisplay();
}

//***********************************************************************************
void colorSub(int option)
{
	// Processes what color the user selects and changes the font color
	switch (option)
	{
	case 0:
		COLOR = RED;
		break;
	case 1:
		COLOR = ORANGE;
		break;
	case 2:
		COLOR = YELLOW;
		break;
	case 3:
		COLOR = GREEN;
		break;
	case 4:
		COLOR = CYAN;
		break;
	case 5:
		COLOR = BLUE;
		break;
	case 6:
		COLOR = MAGENTA;
		break;
	case 7:
		COLOR = BLACK;
		break;
	}

	glutPostRedisplay();
}

//***********************************************************************************
void fontSub(int option)
{
	// Processes what font the user selects and changes the font type
	switch (option)
	{
	case 0:
		FONT = GLUT_BITMAP_8_BY_13;
		LINE_HEIGHT = 13;
		break;
	case 1:
		FONT = GLUT_BITMAP_9_BY_15;
		LINE_HEIGHT = 15;
		break;
	case 2:
		FONT = GLUT_BITMAP_HELVETICA_10;
		LINE_HEIGHT = 10;
		break;
	case 3:
		FONT = GLUT_BITMAP_HELVETICA_12;
		LINE_HEIGHT = 12;
		break;
	case 4:
		FONT = GLUT_BITMAP_HELVETICA_18;
		LINE_HEIGHT = 18;
		break;
	case 5:
		FONT = GLUT_BITMAP_TIMES_ROMAN_10;
		LINE_HEIGHT = 10;
		break;
	case 6:
		FONT = GLUT_BITMAP_TIMES_ROMAN_24;
		LINE_HEIGHT = 24;
		break;
	}

	glutPostRedisplay();
}

//***********************************************************************************
void helpSub(int option)
{
	switch (option)
	{
	case 0:
		glutSetWindow(INFO_WINDOW_ID);
		glutShowWindow();
		break;
	case 1:
		glutSetWindow(INFO_WINDOW_ID);
		glutIconifyWindow();
		break;
	case 2:
		glutSetWindow(INFO_WINDOW_ID);
		glutHideWindow();
		break;
	}

	glutPostRedisplay();
}


//***********************************************************************************

void saveFile(){
	ofstream myFile;
	myFile.open("C://Temp//typed.txt");
	for (int i = 0; i <= (int)INPUT.size() - 1; i++)
	{
		for (int j = 0; j <= (int)INPUT[i].length() - 1; j++)
		{
			myFile << (char)INPUT[i][j];
		}
		myFile << endl;
	}
	myFile.close();
}


//***********************************************************************************
void menuFunctions(int option)
{
	if (option == 1)
		exit(0);
	if (option == 9){
		saveFile();
	}
}

//***********************************************************************************
void processMouseClick(int button, int state, int x, int y)
{
	int clickPosition;
	if (!button)	//right click
	{
		clickPosition = floor(y / LINE_HEIGHT) + 1;
		if (clickPosition > LINE_NUMBER)
		{
			int blankLinesToAdd = (clickPosition - LINE_NUMBER);
			for (int k = 0; k < blankLinesToAdd; k++)
			{
				INPUT.push_back("");
				LINE_NUMBER++;
			}
		}
		else if (clickPosition < LINE_NUMBER)
		{
			LINE_NUMBER = clickPosition;
		}
	}
}

//***********************************************************************************
void printText(string text, int x, int y)
{
	// takes a string and displays it at the coordinates given
	glRasterPos2i(x, y);
	for (size_t i = 0; i < text.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
}

//***********************************************************************************
void helpWindow()
{
	// Info Window Instructions
	glColor3fv(BLACK);
	string text;

	text = "DOCUMENTATION";
	printText(text, -60, 285);
	text = "HOW TO USE THIS PROGRAM";
	printText(text, -400, 245);
	text = "1) The other window is the Text Editor";
	printText(text, -375, 225);
	text = "2) To display your text, type your message on the keyboard.";
	printText(text, -375, 205);
	glColor3fv(RED);
	text = "***NOTE: You choose any line to start typing just by clicking on the line and typing your message.";
	printText(text, -400, 185);
	text = "***NOTE: Pressing either the 'Backspace' or 'Delete' key on your keyboard will erase the last letter you typed.***";
	printText(text, -400, 165);
	glColor3fv(BLACK);
	text = "CHANGING FONT COLOR AND TYPE";
	printText(text, -400, 125);
	glColor3fv(RED);
	text = "***NOTE: Default color and font is set to Black and size 12 Helvetica respectively.***";
	printText(text, -400, 105);
	glColor3fv(BLACK);
	text = "1) Right-click in the window titled 'Notepad--'.";
	printText(text, -375, 85);
	text = "2) A menu will appear in the window with these options: Info Window, Select Color, Select Font, Save File, and Exit Program";
	printText(text, -375, 65);
	text = "3) To change the font color, highlight 'Select Color'. Click on a color to make the message change to that color.";
	printText(text, -375, 45);
	text = "4) To change the font type, highlight 'Select Font'. Click on a font to make the message change to that font style.";
	printText(text, -375, 25);
	glColor3fv(RED);
	text = "***NOTE: The number after the colon( : ) is the size.***";
	printText(text, -400, 5);
	glColor3fv(BLACK);
	text = "EXITING THE PROGRAM";
	printText(text, -400, -35);
	text = "1) Right-click in the window titled 'Notepad--'.";
	printText(text, -375, -55);
	text = "2) A menu will appear in the window with these options: Info Window, Select Color, Select Font, Save File, and Exit Program";
	printText(text, -375, -75);
	text = "3) To exit the program, click on 'Exit Program'.";
	printText(text, -375, -95);
	text = "SAVING THE FILE";
	printText(text, -400, -135);
	text = "1) Right-click in the window titled 'Notepad--'.";
	printText(text, -375, -155);
	text = "2) A menu will appear in the window with these options: Info Window, Select Color, Select Font, Save File, and Exit Program";
	printText(text, -375, -175);
	text = "3) To save the file, click on Save File.";
	printText(text, -375, -195);
	glColor3fv(RED);
	text = "***NOTE: The file will be saved as a text document called 'typed' in the Temp folder.";
	printText(text, -400, -215);
	glColor3fv(BLACK);
	text = "INFO WINDOW MENU";
	printText(text, -400, -255);
	text = "1) Right-click in the window titled 'Notepad--'.";
	printText(text, -375, -275);
	text = "2) A menu will appear in the window with these options: Info Window, Select Color, Select Font, Save File, and Exit Program";
	printText(text, -375, -295);
	text = "3a) To Show the Help Window, click 'Show Window'.";
	printText(text, -375, -315);
	text = "3b) To Minimize the Help Window, click 'Minimize Window'.";
	printText(text, -375, -335);
	text = "3c) To Close the Help Window, click 'Hide Window'.";
	printText(text, -375, -355);
}

//***********************************************************************************
void myInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background color: white 
	gluOrtho2D(0, 600, 0, 600);			// specify a viewing area
}

//***********************************************************************************
void myHelpInit()
{
	glClearColor(1, 1, 1, 0);			// specify a background color: black
	gluOrtho2D(-400, 400, -400, 300);	// specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	typingText();
	glFlush();		// flush out the buffer contents
}

//***********************************************************************************
void myHelpDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	helpWindow();
	glFlush();		// flush out the buffer contents
}

//***********************************************************************************

void main()
{
	////////// EDITOR WINDOW //////////
	glutInitWindowSize(600, 600);							// specify a window size
	glutInitWindowPosition(0, 0);							// specify a window position
	EDITOR_WINDOW_ID = glutCreateWindow("Notepad--");	// create a titled window

	myInit();									// setting up
	glutDisplayFunc(myDisplayCallback);			// register a callback

	int colorMenu = glutCreateMenu(colorSub);	// creates the Color Menu
	glutAddMenuEntry("RED", 0);
	glutAddMenuEntry("ORANGE", 1);
	glutAddMenuEntry("YELLOW", 2);
	glutAddMenuEntry("GREEN", 3);
	glutAddMenuEntry("CYAN", 4);
	glutAddMenuEntry("BLUE", 5);
	glutAddMenuEntry("MAGENTA", 6);
	glutAddMenuEntry("BLACK", 7);

	int fontMenu = glutCreateMenu(fontSub);		// creates the Font Menu
	glutAddMenuEntry("8 BY 13", 0);
	glutAddMenuEntry("9 BY 15", 1);
	glutAddMenuEntry("HELVETICA: 10", 2);
	glutAddMenuEntry("HELVETICA: 12", 3);
	glutAddMenuEntry("HELVETICA: 18", 4);
	glutAddMenuEntry("TIMES NEW ROMAN: 10", 5);
	glutAddMenuEntry("TIMES NEW ROMAN: 24", 6);

	int helpMenu = glutCreateMenu(helpSub);		// creates the Help Menu
	glutAddMenuEntry("Show Window", 0);
	glutAddMenuEntry("Minimize Window", 1);
	glutAddMenuEntry("Hide Window", 2);

	int mainMenu = glutCreateMenu(menuFunctions);	// creates the menu you see
	glutAddSubMenu("Info Window", helpMenu);
	glutAddSubMenu("Select Color", colorMenu);
	glutAddSubMenu("Select Font", fontMenu);
	glutAddMenuEntry("Save File", 9);
	glutAddMenuEntry("Exit Program", 1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);		// menu appears after clicking the RMB
	glutMouseFunc(processMouseClick);		// for changing the position

	glutKeyboardFunc(type);					// allows typing in the text editor

	////////// INFO WINDOW //////////
	glutInitWindowSize(750, 600);				// specify a window size
	glutInitWindowPosition(700, 0);				// specify a window position
	INFO_WINDOW_ID = glutCreateWindow("Help");
	myHelpInit();
	glutDisplayFunc(myHelpDisplayCallback);

	glutMainLoop();							// get into an infinite loop
}