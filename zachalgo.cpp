#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

char zachmove(int rounds, string oppmoves, string &mymoves){ //this algorithm attempts to find a pattern in my opponents moves by attempting to see if the last five moves had been played prior
    char movelist[3] = {'R', 'P', 'S'}; 
    srand(time(NULL));


    if(rounds < 6){
        int randmove = rand()%3 //randomizes the first six rounds of play(before algorithm can make predictions)
        return movelist[randmove];
    }
    else{ //if its round 7 or above
        
        string lastfive = oppmoves.substr(rounds-5, 5); //create a substring of the last five moves
        size_t found = oppmoves.find(lastfive); //find the position of the substring in the list of opponent moves
        if (found != string::npos){ //if the substring is found, read the following move and then counter it
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
            
            int randmove = rand()%3
            return movelist[randmove];
        }
    }
    
}


char altmove(int rounds, string oppmoves, string mymoves){ //counters the last move

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