#include <iostream>

using namespace std;

class Frequency{
    // variables for move tracking
    float rockFreq;
    float paperFreq;
    float scissorFreq;

    int rockSum;
    int paperSum;
    int scissorSum;

    string moves;

    public:
    Frequency(){
        rockFreq = 0.00;
        paperFreq = 0.00;
        scissorFreq = 0.00;

        rockFreq = 0.00;
        paperFreq = 0.00;
        scissorFreq = 0.00;
    }
    char frequency();




};

//char prevMoves[5] = {'R', 'R', 'R', 'R', 'R'};

char Frequency::frequency(){

    // gets sum of each move
    for(int i=0; i < moves.length(); i++){
        char sc = moves[i];
        switch(sc){
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
        }
    }

    // gets frequency of each moves occurance
    rockFreq = rockSum/moves.length();
    paperFreq = paperSum/moves.length();
    scissorFreq = scissorSum/moves.length();


    
    if(rockFreq > paperFreq && rockFreq > scissorFreq){
        return 'P';
    }

    if(paperFreq > rockFreq && paperFreq > scissorFreq){
        return 'S';
    }

    if(scissorFreq > paperFreq && scissorFreq > rockFreq){
        return 'R';
    }
    return 0;
}