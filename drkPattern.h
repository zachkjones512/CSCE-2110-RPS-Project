#include <iostream>
using namespace std;
class Pattern{
    string moves;
    string prevPattern, prevR, prevP, prevS;
    int nR, nP, nS;

    public:
    Pattern(){
        moves = "";
        prevPattern = "";
        prevR = "";
        prevP = "";
        prevS = "";
        nR = 0;
        nP = 0;
        nS = 0;
    }

    char ChooseMove(char);
    char patternFinder(char);
    void PrintStats();

};