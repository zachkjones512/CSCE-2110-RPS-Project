#include "drkFreq.h"

//char prevMoves[5] = {'R', 'R', 'R', 'R', 'R'};

char Frequency::SelectRand(){
    int randMove = rand() % 3;
    switch(randMove){
            case 0:
                return 'R';
                break;
            case 1:
                return 'P';
                break;
            default:
                return 'S';
                break;
    }
}

void Frequency::PrintStats(){
    cout << "Sums" << endl;
    cout << "Rock: " << rockSum << endl;
    cout << "Paper: " << paperSum << endl;
    cout << "Scissors: " << scissorSum << endl;

    cout << "Frequencies" << endl;
    cout << "Rock: " << rockFreq << endl;
    cout << "Paper: " << paperFreq << endl;
    cout << "Scissors: " << scissorFreq << endl;
}  

char Frequency::ChooseMove(char prevMove){

    //cout << moves << endl;
    if(prevMove == '|'){
        return SelectRand();
    }else{
        moves += prevMove;
        switch(prevMove){
            case 'R':
                rockSum++;
                break;
            
            case 'P':
                paperSum++;
                break;

            case 'S':
                scissorSum++;
                break;
            
            default:
                cout << "invalid move" << endl;
                break;
        }
    }



    // gets frequency of each moves occurance
    rockFreq = ((float)rockSum/(float)moves.length());
    paperFreq = ((float)paperSum/(float)moves.length());
    scissorFreq = ((float)scissorSum/(float)moves.length());


    
    if(rockFreq > paperFreq && rockFreq > scissorFreq){
        return 'P';
    }

    if(paperFreq > rockFreq && paperFreq > scissorFreq){
        return 'S';
    }

    if(scissorFreq > paperFreq && scissorFreq > rockFreq){
        return 'R';
    }

    
    return SelectRand();
}