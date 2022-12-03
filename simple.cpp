#include <iostream>
#include "simple.h"

using namespace std;

char Simple::RPS(char prevMove){
    count++;
    int sc = count % 3;
    switch(sc){
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

char Simple::previousMove(char prevMove){
    switch(prevMove){
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