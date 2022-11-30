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

        rockSum = 0;
        paperSum = 0;
        scissorSum = 0;
    }
    char ChooseMove(char);
    char SelectRand();
    void PrintStats();




};