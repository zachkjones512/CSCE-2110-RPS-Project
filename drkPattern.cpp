#include <iostream>
#include "drkPattern.h"

using namespace std;

char Pattern::patternFinder(char prevMove){
    int patternLength = 4;
    if(moves.length() >= 4){
        while(patternLength > 1){
            prevPattern = moves.substr(moves.size()-(patternLength-1));
            prevR = prevPattern + 'R';
            prevP = prevPattern + 'P';
            prevS = prevPattern + 'S';
            nR = 0;
            nP = 0;
            nS = 0;
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
            //PrintStats();

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

void Pattern::PrintStats(){
    cout << "Pattern occurances" << endl;
    cout << "Rock:      " << nR << endl;
    cout << "Paper:     " << nP << endl;
    cout << "Scissors:  " << nS << endl;
}