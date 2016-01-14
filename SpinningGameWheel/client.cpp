#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "SpinningWheel.h"
#include "Player.h"



/**
 
 This program plays the Spinning Wheel game for 3 players. The game begins with each player taking turns with spinning the wheel, in playerSpin(), which has the player spin the wheel for a value which is added to their score, and a choice to spin the wheel a second time for another value added to their existing score. After each player gets their chance to spin the wheel, the game's winner(s), which happens in winner(), is decided with comparing which player(s) has a score of 100 or has the highest score, all without reaching a score of over 100, in which case the player automatically loses. Ties between players are possible as well. After the winner(s) has been decided, the game asks whether they would like to play again or not, in playAgain().
 
 @author Jennelle Lai
 @class client program
 @date October 13, 2015
 @lab 2: SpinningWheel
 @instructor Abensohn
 
 */



const int NUM_SPINS = 2; //Max number of spins that a player can spin



//Player spins the wheel
void playerSpin(Player *player, string spins[], SpinningWheel *gameWheel, int &over100Count);

//Determines the winner
void winner(int player1Points, int player2Points, int player3Points);

//Asks whether the user wants to replay the game
bool playAgain(bool &playResponse);



int main()
{
    srand((unsigned)time(nullptr));
    
    string spins[NUM_SPINS] = {"First Spin: ", "Second Spin: "}; //The round number of the spin
    bool playResponse; //Stores whether the player wants to play again or not
    int over100Count = 0; //Stores how many players have exceed over 100 in score
    
    do
    {
        cout << "Game Show" << endl << endl;
        
        SpinningWheel *gameWheel = new SpinningWheel;
        
        Player *Player_1 = new Player,
        *Player_2 = new Player,
        *Player_3 = new Player;
        
        cout << "Player_1" << endl;
        
        playerSpin(Player_1, spins, gameWheel, over100Count); //First player spins the wheel
        
        cout << "Player_2" << endl;
        
        playerSpin(Player_2, spins, gameWheel, over100Count); //Second player spins the wheel
        
        cout << "Player_3" << endl;
        
        playerSpin(Player_3, spins, gameWheel, over100Count); //Third player spins the wheel
        
        int player1Points = Player_1->totalPoints(); //Stores the first player's score
        int player2Points = Player_2->totalPoints(); //Stores the second player's score
        int player3Points = Player_3->totalPoints(); //Stores the third player's score
        
        //Determines the winner between the players
        winner(player1Points, player2Points, player3Points);
        
        cout << endl;
        
        //Asks whether the user wants to play again or not
        playAgain(playResponse);
    } while (playResponse);
    
}








/**
 
 This playerSpin method has the player spin the wheel for a value which is added to their score, and a choice to spin the wheel a second time for another value added to their existing score. Special case is if the first two players have already scored over 100, then the third player can only spin once.
 
 @param player A Player, spins[] A string array, gameWheel A SpinningWheel, over100Count A nonnegative integer
 @pre player is a Player, spins[] a non-empty array of strings, gameWheel is a SpinningWheel, over100Count is a nonnegative integer
 @post player will have spun the gameWheel at least once and have a score
 
 */

void playerSpin(Player *player, string spins[], SpinningWheel *gameWheel, int &over100Count)
{
    int spinIndex = 0; //Stores the starting index for spins[]
    char spinAgainResponse; //Stores the user's input to whether or not they want to spin the wheel again
    
    do
    {
        cout << left << setw(13) << spins[spinIndex];
        
        //player spins the gameWheel
        player->spin(*gameWheel);
        
        //If the player's score is less than 100 and if the player has only spun once
        if (player->totalPoints() < 100 && spinIndex < 1)
        {
            cout << endl << "Points so far: " << player->totalPoints() << endl;
            
            //If the number of players that have exceed a score of over 100 is less than 2
            if (over100Count < 2)
            {
                cout << "Spin again (y/n)? ";
                cin >> spinAgainResponse;
                
                //If the user wants to spin again
                if (tolower(spinAgainResponse) == 'y')
                {
                    spinIndex++;
                }
                
                cout << endl;
            }
            else
            {
                spinAgainResponse = 'n';
            }
        }
        else
        {
            //Player doesn't spin again
            spinAgainResponse = 'n';
            
            //If the player's score is less than or equal to 100
            if (player->totalPoints() <= 100)
            {
                cout << endl << "Total Points: " << player->totalPoints() << endl;
            }
            else
            {
                cout << endl << "Total Points: Over 100" << endl;
                over100Count++;
            }
            
            cout << endl;
        }
    } while (tolower(spinAgainResponse) == 'y'); //Do again only if player wants to spin again
    
}








/**
 
 This winner method compares the points between all three players to determine the winner(s) of the game
 
 @param player1points A positive integer, player2points A positive integer, player3points A positive integer
 @pre player1points is a positive integer, player2points is a positive integer, player3points is a positive integer
 @post Prints out the winners of the game
 
 */

void winner(int player1Points, int player2Points, int player3Points)
{
    //If all players' scores exceed over 100
    if (player1Points > 100 && player2Points > 100 && player3Points > 100)
    {
        cout << "No one wins!";
    }
    //If all players' scores equal to 100
    else if (player1Points == 100 && player2Points == 100 && player3Points == 100)
    {
        cout << "Tie!";
    }
    //If only to players' scores equal to 100
    else if (player1Points == 100 && player2Points == 100)
    {
        cout << "Player_1 and Player_2 wins!";
    }
    else if (player2Points == 100 && player3Points == 100)
    {
        cout << "Player_2 and Player_3 wins!";
    }
    else if (player1Points == 100 && player3Points == 100)
    {
        cout << "Player_1 and Player_3 wins!";
    }
    //If only one player's score equals to 100
    else if (player1Points == 100)
    {
        cout << "Player_1 wins!";
    }
    else if (player2Points == 100)
    {
        cout << "Player_2 wins!";
    }
    else if (player3Points == 100)
    {
        cout << "Player_3 wins!";
    }
    //If all players' scores don't exceed over 100
    else if (!(player1Points > 100) && !(player2Points > 100) && !(player3Points > 100))
    {
        //If all players' scores are the same
        if (player1Points == player2Points && player1Points == player3Points)
        {
            cout << "Tie!";
        }
        //If two players' scores are the same and they're greater than the other player's score
        else if (player1Points == player2Points && player1Points > player3Points)
        {
            cout << "Player_1 and Player_2 wins!";
        }
        else if (player2Points == player3Points && player2Points > player1Points)
        {
            cout << "Player_2 and Player_3 wins!";
        }
        else if (player1Points == player3Points && player1Points > player2Points)
        {
            cout << "Player_1 and Player_3 wins!";
        }
        //If one player's score is greater than both of the other players' scores
        else if (player1Points > player2Points && player1Points > player3Points)
        {
            cout << "Player_1 wins!";
        }
        else if (player2Points > player1Points && player2Points > player3Points)
        {
            cout << "Player_2 wins!";
        }
        else if (player3Points > player1Points && player3Points > player2Points)
        {
            cout << "Player_3 wins!";
        }
    }
    //If one player's score exceeds over 100 and the other players' scores are under 100
    else if (!(player1Points > 100) && !(player2Points > 100) && (player3Points > 100))
    {
        //If those two players' scores are equal
        if (player1Points == player2Points)
        {
            cout << "Player_1 and Player_2 wins!";
        }
        //If one of the players' score is greater than the other player's score
        else if (player1Points > player2Points)
        {
            cout << "Player_1 wins!";
        }
        else
        {
            cout << "Player_2 wins!";
        }
    }
    //If one player's score exceeds over 100 and the other players' scores are under 100
    else if ((player1Points > 100) && !(player2Points > 100) && !(player3Points > 100))
    {
        //If those two players' scores are equal
        if (player2Points == player3Points)
        {
            cout << "Player_2 and Player_3 wins!";
        }
        //If one of the players' score is greater than the other player's score
        else if (player2Points > player3Points)
        {
            cout << "Player_2 wins!";
        }
        else
        {
            cout << "Player_3 wins!";
        }
    }
    //If one player's score exceeds over 100 and the other players' scores are under 100
    else if (!(player1Points > 100) && (player2Points > 100) && (player3Points > 100))
    {
        //If those two players' scores are equal
        if (player1Points == player3Points)
        {
            cout << "Player_1 and Player_3 wins!";
        }
        //If one of the players' score is greater than the other player's score
        else if (player1Points > player3Points)
        {
            cout << "Player_1 wins!";
        }
        else
        {
            cout << "Player_3 wins!";
        }
    }
    //If two players' scores exceed over 100 and one player's score is under 100
    else if (!(player1Points > 100) && (player2Points > 100) && (player3Points > 100))
    {
        cout << "Player_1 wins!";
    }
    else if ((player1Points > 100) && !(player2Points > 100) && (player3Points > 100))
    {
        cout << "Player_2 wins!";
    }
    else if ((player1Points > 100) && (player2Points > 100) && !(player3Points > 100))
    {
        cout << "Player_3 wins!";
    }
}









/**
 
 This playAgain method asks whether or not the user wants to play the Spinning Wheel game again
 
 @param playResponse A boolean
 @pre playResponse is a boolean
 @post returns true if the user wants to play again or returns false if the user does not want to play again
 
 */

bool playAgain(bool &playResponse) {
    char playAgain; //Stores the user's input to whether or not they want to play the game again
    
    cout << "Play again (y/n)? ";
    cin >> playAgain;
    
    if (playAgain == 'y')
    {
        return playResponse = true; //Returns true if the user wants to play again
    }
    
    return playResponse = false; //Returns false if the user does not want to play again
}