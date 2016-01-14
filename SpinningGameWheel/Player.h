#ifndef Player_h
#define Player_h

#include <iostream>
#include "SpinningWheel.h"
using namespace std;



/*
 
 The Player class represents a player who plays the SpinningWheel game and scores a number of points
 
 Player();
 Precondition: A Player object is declared
 Postcondition: Initializes the player's points to 0
 
 void spin(SpinningWheel &gameWheel);
 Precondition: A Player object is declared and a SpinningWheel object is declared as gameWheel
 Postcondition: The player spins the gameWheel to score points
 
 int totalPoints();
 Precondition: A Player object is declared
 Postcondition: Returns the player's total score
 
 */

class Player
{
private:
    int points;
public:
    Player();
    void spin(SpinningWheel &gameWheel);
    int totalPoints();
};

#endif /* Player_h */
