#include <iostream>
#include <iomanip>
#include <ctime>
#include "SpinningWheel.h"
using namespace std;



/**
 
 This SpinningWheel class runs the wheel for the SpinningWheel game. The wheel has 20 values, which are integers that are multiples of 5 from 5 to 100, and are randomized in order, which is done in the SpinningWheel(). Then, each time the wheel is spun, spin(), the wheel advances a random number of steps between 22 to 42 and returns the value at where it stops.
 
 @author Jennelle Lai
 @class SpinningWheel
 @date October 13, 2015
 @lab 2: SpinningWheel
 @instructor Abensohn
 
 */



/**
 
 This SpinningWheel() constructor initiates the wheel to 20 values, which are integers that are multiples of 5 from 5 to 100, and are randomized in order.
 
 @param none
 @pre none
 @post SpinningWheel's values are in randomized order
 
 */

SpinningWheel::SpinningWheel()
{
    int count = 0; //Starting count of every integer between 5 to 100 that is a multiple of 5
    int tempValue; //Stores a value temporarily used to swapping with another value to randomize the order of values in the wheel
    int randIndex; //Stores the randomly generated index to store a value in
    index = 0; //Starting index of the wheel for spinning
    
    int countIndex = 0;
    
    for (int i = 0; i < 20; i++)
    {
        values[i] = count + 5;
        count = count + 5;
    }
    
    for (int i = 0; i < 20; i++)
    {
        tempValue = values[i];
        randIndex = (rand()+1)%20;
        values[i] = values[randIndex];
        values[randIndex] = tempValue;
    }
}







/**
 
 This spin() method initiates the wheel to 20 values, which are integers that are multiples of 5 from 5 to 100, and are randomized in order.
 
 @param none
 @pre none
 @post SpinningWheel's values are in randomized order
 
 */

int SpinningWheel::spin()
{
    int randNumber = rand() % (41 - 20) + 22; //Stores a random number between 22 to 42 as the number of values the wheel is to advance
    int count = 0; //Stores the number to make sure the wheel advances each step
    int indexFlag = index; //Stores the index of where the SpinningWheel should start from where it left off previously
    int indexCopy = indexFlag; //Stores the index so that this could be incremented in the while loop to keep track of which index the wheel should advance to
    
    while (count < randNumber)
    {
        int startIndex;
        
        //startIndex begins at the index of where the wheel previously left off and as long as the count is less than the random number of steps that the wheel should advance, startIndex is incremented
        for (startIndex = indexCopy; startIndex < 20 && count < randNumber; startIndex++)
        {
            cout << right << setw(4) << values[startIndex];
            count++;
            
            //If count divided into 20's remainder is 0, then start over at the beginning index
            if (count%20 == 0)
            {
                cout << endl << right << setw(13) << " ";
            }
        }
        indexCopy = 0; //Restarts the wheel to the first index
    }

    index = (index + randNumber)%20; //The new index at which the wheel leaves off aat
    
    return values[(count+indexFlag-1)%20]; //return the value of the index
}