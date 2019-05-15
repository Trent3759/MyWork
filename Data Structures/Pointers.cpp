/*
 Name: Trenton Scott
 Date: 28/01/2016
 Assignment: Pointers Lab
 Platform/IDE: OSX 10.11.3 (15D21) / XCODE 7.2 (7C68)
 Description: Lab to test knowledge of pointers
 */

#include <iostream>
#include <iterator>

char *c = new char;
char d = 'b';
*c = 'a';
cout << *c << ' ';
c = &d;
cout << *c << endl;