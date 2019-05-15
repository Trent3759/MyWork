/*==================================================================================================
PROGRAMMER:				Trent Scott
COURSE:					CSC 525/625
MODIFIED BY:			Trent Scott
LAST MODIFIED DATE:		10/31/2016
DESCRIPTION:			Matrix Multiplication
FILES:					lab12.cpp, (myCPPproj.sln, ...)
IDE/COMPILER:			MicroSoft Visual Studio 2013
INSTRUCTION FOR COMPILATION AND EXECUTION:
1.		Double click on myCPPproj.sln	to OPEN the project
2.		Press Ctrl+F7					to COMPILE
3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int array1[10][10], array2[10][10], result[10][10]; //arrays
int rows1, cols1, rows2, cols2; //metadata 
int i, j, k; //counters

void readFile() {
	char fileDigit;
	string fileExtension = ".txt";
	string fileToOpen;
	int data; //data holder

	ifstream myFile;
	string filePath = "C:\\Temp\\a";
	cout << "Enter digit(s) for file 1: ";
	cin >> fileDigit;

	fileToOpen = filePath + fileDigit + fileExtension;

	myFile.open(fileToOpen);

	if (myFile.is_open()) {

		myFile >> rows1 >> cols1;
		int x = 0;//array index
		int y = 0;
		while (myFile >> data) {
			array1[x][y] = data;
			y++;
			if (y == cols1) {
				y = 0;
				x++;
			}
		}
	}
	else {
		cout << "\nOoops. Something went wrong. Please try again. \n\n";
		readFile();
		return;
	}//end if file open 2


	//load 2nd file to array

	cout << "\nEnter digit(s) for file 2: ";
	cin >> fileDigit;

	fileToOpen = filePath + fileDigit + fileExtension;
	ifstream myFile2;
	myFile2.open(fileToOpen);

	if (myFile2.is_open()) {

		myFile2 >> rows2 >> cols2;
		int x = 0;//array index
		int y = 0;
		while (myFile2 >> data) {
			array2[x][y] = data;
			y++;
			if (y == cols2) {
				y = 0;
				x++;
			}
		}
	}
	else {
		cout << "\nOoops. Something went wrong. Please try again. \n\n";
		readFile();
		return;
	}//end if file open 2


}//end readFile

void mult(int firstArray[10][10], int secondArray[10][10]) {
	cout << secondArray[0][0] << " \n";

	for (i = 0; i < rows1; ++i)
		for (j = 0; j < cols2; ++j)
		{
			result[i][j] = 0;
		}

	for (i = 0; i < rows1; ++i)
		for (j = 0; j < cols2; ++j)
			for (k = 0; k < cols1; ++k)
			{
				result[i][j] += firstArray[i][k] * secondArray[k][j];
			}
}

int main() {
	
	readFile();
	mult(array1, array2);

	// Displaying the multiplication of two matrix.
	cout << endl << "Output Matrix: " << endl;
	for (i = 0; i < rows1; ++i)
		for (j = 0; j < cols2; ++j)
		{
			cout << " " << result[i][j];
			if (j == cols2 - 1)
				cout << endl;
		}
		
	int holdProgram;
	cin >> holdProgram;

	return 0;
}