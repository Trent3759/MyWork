/*
 Name: Trent Scott
 Date: 02/19/16
 Description: DiceRace Class
 
 This program is intended to test classes with a previously made program (Dice Race).
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::cin;

bool FINISHED = false;
int GAMES = 0;
int CUR_GAME = 1;//cannot have current game at 0;
class Player {
public:
    //didnt provide Player() constructor
    //program required to set name.
    //must user Player(string name);
    Player(string name);                //constructor for input
    ~Player();                          //destructor
    void reset();                       //reset some variables
                                            //for next game
    
    unsigned short getGameNumber();
    const int WIN = 20;                 //number to win game.
    
    bool operator== (const Player& player) const;  //overload ==
    
    void move(int roll);  //Move a player --setter
    int getPosition();  //Position  --getter
    void tumble(int dice, int enemyScore);  //tumble player
    void printTurn(int dice);
    int getWins();

    
private:
    int position;
    string name;
    int wins;
    
};


/** Class Constructors
 */

Player::Player(string playerName) {  //constructor
    position = 0;
    name = playerName;  //parameters and fields can have different names
    wins = 0;
}

/** Class Members
 */

/*  Methods  */
bool Player::operator== (const Player& player2) const {
    /* Override for is equal to operator */
    // Since declared as member function, access to one of the two
    // objects is done directly. position is LHS player
    return position == player2.position;
}

//increase player score and test if won
void Player::move(int roll) {
    position += roll;
    if (position >= 20){
        printTurn(roll);
        FINISHED = true;
        wins++; //increase players win count.
        cout << name << " wins game " << CUR_GAME << "!"
            << "\n\n"; //new lines for start of new game.
    }
}
//return position
int Player::getPosition(){ return position; }

void Player::tumble(int dice, int enemyScore){
    position -= (rand() % 3) + 1;
    if (name == "Jack"){
        cout << dice << "\t" << position <<  "\t" << enemyScore << "\tTumble Jack!\n";
    }
    else {
        cout << dice << "\t" << enemyScore << "\t" << position << "\tTumble Jill!\n";
    }
}

//print turn
void Player::printTurn(int dice){
    if (name == "Jack"){
    //print jacks turn
        cout << dice << "\t" << position << "\n";
    }
    else if (name == "Jill"){
        cout << dice << "\t\t" << position << "\n";
    }
    else {
        //if player has no name..error in program and exit game.
        cout << "ERROR ERROR ERROR\nEXITING PROGRAM\n\n";
        FINISHED = true;
    }
}

//reset some variables for next round.
void Player::reset() { position = 0; }

//return amount of wins.
int Player::getWins(){return wins;}

//destructor
Player::~Player(){}

int roll(){ return rand() % 6 + 1; }

void startGame(){
    cout << "Please enter an odd number of games to play: ";
    cin >> GAMES;
    if (GAMES % 2 == 0){
        cout << "\n\n***Input not odd. Please try again.***\n\n";
        startGame();
    }
}

int main() {
    //see top of program to view global variables.
    srand((int)time(NULL));
    
    Player jack("Jack");
    Player jill("Jill");
    
    startGame(); //get the game rolling. Ask for # of games.

    for (int i = GAMES; i != 0; i--){
        
        // Print column headers
        cout << "Roll \tJack \tJill \n--------------------" << endl;
        while (not FINISHED){
            //jacks turn
            //made funtion for int that way I save code.
            int rollDice = roll();
            jack.move(rollDice);
        
            if (jack == jill){
                jill.tumble(rollDice, jack.getPosition());
            }
            else if (not FINISHED){//only print this if game is not finished.
                jack.printTurn(rollDice);
            }
        
            //FINISHED is checked/set per move. Below statement checks if game is over, midgame.
            if (FINISHED){break;}
            rollDice = roll();
            jill.move(rollDice);
        
            if (jill == jack){
                jack.tumble(rollDice, jill.getPosition());
            }
            else if (not FINISHED){ //only print if game not finished
                jill.printTurn(rollDice);
            }
        
            //winner check here is done in loop. No need for overkill.
        }
        //destroy players.
        jack.reset();
        jill.reset();
        CUR_GAME++;
        FINISHED = false;
    }
    
    //print amount of wins
    cout << "\nJack won " << jack.getWins() << " time(s) and "
        << "Jill won " << jill.getWins() << " time(s).\n";
    //print champion.
    if (jill.getWins() < jack.getWins()){
        cout << "Jack is the Dice Race Grand Champion!\n\n";
    }
    else {
        cout << "Jill is the Dice Race Grand Champion\n\n";
    }
    
    getchar();
}