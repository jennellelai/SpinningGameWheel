#include "Player.h"
#include "SpinningWheel.h"



/**
 
 This PLayer class is a player of the SpinningWheel game. The player starts with a score of 0 points. And for each time the player spins the wheel, the player accumulates points to their total score.
 
 @author Jennelle Lai
 @class Player
 @date October 13, 2015
 @lab 2: SpinningWheel
 @instructor Abensohn
 
 */



/**
 
 This Player constructor initiates the player's points to 0.
 
 @param none
 @pre none
 @post points is 0
 
 */

Player::Player()
{
    points = 0;
}








/**
 
 This spin method spins the gameWheel so that player accumulates points.
 
 @param gameWheel A SpinningWheel
 @pre gameWheel is a SpinningWheel
 @post more points is accumulated
 
 */

void Player::spin(SpinningWheel &gameWheel)
{
    points = points + gameWheel.spin();
}








/**
 
 This totalPoints() method returns the player's total score of points
 
 @param none
 @pre none
 @post Returns points
 
 */

int Player::totalPoints()
{
    return points;
}