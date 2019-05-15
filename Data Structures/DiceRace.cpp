/*********
 Name: Trenton D Scott
 Date: 01/31/2016
 Assignment: Dice Race!
 Platform / IDE: Mac OSX 10.11.3 (15D21) // XCODE 7.2 (7C68)
 
 Description: Write a game program called Dice Race! It has two players, Jack and Jill, and a board with 20 squares. Players take turns by rolling a 6-sided die and move forward the number of squares shown. If a player lands on the same square as his or her opponent, the opponent tumbles back a random number of 1 – 3 squares. The first player to reach the "top" of the hill (square 20) wins.
 
 *********/

#include <iostream>
#include <time.h>  //for seeding the random number generator
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */


using namespace std;


int roll(){
    return rand() % 6 + 1;
}

int main(){
    srand((int)time(NULL));
    
    bool finished = false;
    int jack=0;
    int jill=0;
    string winner = "";
    
    cout << "Roll\tJack\tJill\n";
    cout << "-----------------------\n";
    
    while (not finished){
        //jacks turn
        //made funtion for int that way I save code.
        int rollJack = roll();
        //add roll to jacks current total.
        jack += rollJack;
        if (jack == jill){
            jill -= rand() % 3 + 1;
            cout << rollJack << "\t" << jack << "\t" << jill << "\tTumble Jill!\n";
        }else {}
        
        if (jack >= 20){
            finished = true;
            winner = "Jack";
            continue;
        }
        int rollJill = roll();
        jill += rollJill;
        
        if (jill == jack){
            jack -= rand() % 3 + 1;
            cout << rollJill << "\t" << jack << "\t" << jill << "\tTumble Jack!\n";
        }else {cout << rollJill << "\t\t" << jill << "\n";}
        
        if (jill >= 20){
            finished = true;
            winner = "Jill";
        }
        
    }
    
    cout << winner << " wins!\n";
    return 0;
}