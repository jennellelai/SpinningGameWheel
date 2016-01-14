#ifndef SpinningWheel_h
#define SpinningWheel_h

#include <iostream>
using namespace std;



/*
 
 The SpinningWheel class represents a wheel that has 20 values and returns a value at a certain index
 
 SpinningWheel();
 Precondition: A SpinningWheel object is declared
 Postcondition: Initializes the SpinningWheel's values in randomized order and index to 0
 
 int spin();
 Precondition: A SpinningWheel object is declared
 Postcondition: Spins the wheel by having it advance a number of randomized steps and returns the value at the index it stops at

*/

class SpinningWheel
{
private:
    static const int NUM_VALUES = 20;
    int values[NUM_VALUES];
    int index;
public:
    SpinningWheel();
    int spin();
};

#endif /* SpinningWheel_h */
