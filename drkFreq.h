#include <iostream>

using namespace std;

class Frequency{
    // frequencies of each move's occurance
    float rockFreq;
    float paperFreq;
    float scissorFreq;

    // number of times each move played by opponent
    int rockSum;
    int paperSum;
    int scissorSum;

    // stores moves as a string
    string moves;

    public:
    // constructor
    Frequency(){
        rockFreq = 0.00;
        paperFreq = 0.00;
        scissorFreq = 0.00;

        rockSum = 0;
        paperSum = 0;
        scissorSum = 0;
    }
    // functions for algorithm (see drkFreq.cpp for more info)
    char ChooseMove(char);
    char SelectRand();
    void PrintStats();
    void FrequencyFinder(char);




};