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

    public:
    Frequency(){
        rockFreq = 0.00;
        paperFreq = 0.00;
        scissorFreq = 0.00;

        rockFreq = 0.00;
        paperFreq = 0.00;
        scissorFreq = 0.00;
    }
    char chooseMove(char);



};

char prevMoves[5] = {'R', 'R', 'R', 'R', 'R'};

char frequency(char moves[]){
    
    Frequency freq;

    for(int i=0; i < moves.length(); i++){
        char sc = moves[i];
        switch(sc){
            case 'R':
                freq.rockSum++;
                break;
            
            case 'P':
                freq.paperSum++;
                break;

            case 'S':
                freq.scissorSum++;
                break;
            
            default:
                cout << "invalid move" << endl;
        }
    }
    return 0;
}