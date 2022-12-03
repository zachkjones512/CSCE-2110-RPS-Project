/*  Name: Daniel Kaderli
    Date: 11/30/22
    Program: RPS Pattern Algorithm
    Description: This algorithm detects patterns of up to 5 moves,
    and finds the most likely next move by the opponent.
    Variables:
        - prevPattern
            Stores the most recent n<5 moves.

        - prevR, prevP, prevS
            These variables store the predicted next pattern.

        - nR, nP, nS
            These variables hold the occurances of each prevR/P/S.
    
    Functions:
        - PrintStats()
            Debugging function that prints out the sums and 
            frequencies of each move.
        
        - patternFinder()
            Performs pattern searching algorithm that predicts
            most likely next move.
        
        - ChooseMove()
            This function checks to see if the move is valid
            then adds it to the list and calls the
            patternFinder() Function to choose the move.
*/

#include <iostream>
#include "drkPattern.h"

using namespace std;

char Pattern::patternFinder(char prevMove){
    int patternLength = 4;
    if(moves.length() >= 4){
        while(patternLength > 1){
            // prevPattern stores recent moves
            prevPattern = moves.substr(moves.size()-(patternLength-1));

            // predictions of next move
            prevR = prevPattern + 'R';
            prevP = prevPattern + 'P';
            prevS = prevPattern + 'S';

            // # of instances
            nR = 0;
            nP = 0;
            nS = 0;

            // string searching loop finds occurances of each prediction
            string::size_type pos = 0;
            while((pos = moves.find(prevR, pos)) != string::npos){
                ++nR;
                pos += prevR.length();
            }
            pos = 0;
            while((pos = moves.find(prevP, pos)) != string::npos){
                ++nP;
                pos += prevP.length();
            }
            pos = 0;
            while((pos = moves.find(prevS, pos)) != string::npos){
                ++nS;
                pos += prevS.length();
            }

            // Returns move based on results of predictions
            if(nR > nP && nR > nS){
                return 'R';
            }
            if(nP > nR && nP > nS){
                return 'P';
            }
            if(nS > nR && nS > nP){
                return 'S';
            }
            patternLength--;
        }
    }
    return 'S';
}

char Pattern::ChooseMove(char prevMove){
    char p;
    // prevents | from being added to moves
    
    if(prevMove == '|'){
        return 'S';
    }else{ 
        moves += prevMove; // adds each move to the list
        p = patternFinder(prevMove);
    }
    switch(p){
        case 'R':
            return 'P';
            break;
        case 'P':
            return 'S';
            break;
        default:
            return 'R';
            break;
    }
}

// prints stats of each round for debuggings
void Pattern::PrintStats(){
    cout << "Pattern occurances" << endl;
    cout << "Rock:      " << nR << endl;
    cout << "Paper:     " << nP << endl;
    cout << "Scissors:  " << nS << endl;
}