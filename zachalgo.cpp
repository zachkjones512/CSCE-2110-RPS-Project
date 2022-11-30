/*
Name: Zachary Jones
Class: CSCE-2110
File Name: Zachalgo.cpp

This file houses the two individual algorithms put together for the Rock, Paper, Scissors project. 
The first algorithm checks to find the last five moves earlier in the movelist, if found it counters the next.
The second algorithm just counters the last move.

Variables:
mymoves - A string that houses each move made by the first algorithm
oppmoves - A string that houses each move made by the second algorithm 
rounds - total rounds played
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>


class zachAIOne{
    public:
    std::string mymoves;
    int rounds;
    std::string oppmoves;
    zachAIOne(){srand(time(NULL)); rounds = 0; mymoves = ""; oppmoves = "";};
//ALGORITHM 1
char zachmove(int rounds, std::string oppmoves, std::string mymoves){ //this algorithm attempts to find a pattern in my opponents moves by attempting to see if the last five moves had been played prior
    char movelist[3] = {'R', 'P', 'S'}; 


    if(rounds < 6){
        int randmove = rand()%3; //randomizes the first six rounds of play(before algorithm can make predictions)
        return movelist[randmove];
    }
    else{ //if its round 7 or above
        
        std::string lastfive = oppmoves.substr(rounds-5, 5); //create a substring of the last five moves
        size_t found = oppmoves.find(lastfive); //find the position of the substring in the list of opponent moves
        if (found != std::string::npos && found < rounds-5){ //if the substring is found, read the following move and then counter it
            if (oppmoves[found+5] == 'R'){
            return 'P';
            }
            if (oppmoves[found+5] == 'P'){
            return 'S';
            }

            if (oppmoves[found+5] == 'S'){
            return 'R';
            }

        }
        else{ //if the string is not found, return a random move
            
            int randmove = rand()%3;
            return movelist[randmove];
        }
    }
    
}


//ALGORITHM 2
char altmove(int rounds, std::string oppmoves, std::string mymoves){ //counters the last move

    if(rounds < 2){
        return 'R';
    }
    else{
    if(mymoves[rounds] == 'R'){//finds the index in the string array of the most recent move, then counters it
        return 'P';
    }
    if(mymoves[rounds] == 'P'){
        return 'S';
    }
    if (mymoves[rounds] == 'S'){
        return 'R';
    }
    }


}
};