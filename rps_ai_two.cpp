#include "rps_ai_two.h"
#include <cstdlib>
#include <iostream>

//Constructors
RPS_AI_Two::RPS_AI_Two(){
    this->last_move = 4;
    this->move_before_last = 4;
    this->number_moves = 0;
}
//Mutators
int RPS_AI_Two::_CharToRPS(char input){
    switch(input){
        case 'P':
            return 0;
            break;
        case 'R':
            return 1;
            break;
        case 'S':
            return 2;
            break;
        default:
            return 4;
            break;
    }
}
char RPS_AI_Two::_RPSToChar(int input){
    switch(input){
        case 0:
            return 'P';
            break;
        case 1:
            return 'R';
            break;
        default:
            return 'S';
            break;
    }
}
//Accessors
char RPS_AI_Two::ChooseMove(char recent_move){
    move_before_last = last_move;
    last_move = _CharToRPS(recent_move);
    if(number_moves == 0){
        number_moves++;
        return 'S';
    }else if(number_moves == 1){
        number_moves++;
        return 'R';
    }else if(move_before_last == last_move){
        number_moves++;
        return _RPSToChar((move_before_last + 2) % 3);
    }else if(move_before_last + last_move == 1){ // 0 and 1
        number_moves++;
        return _RPSToChar(0);
    }else if(move_before_last + last_move == 3){ // 1 and 2
        number_moves++;
        return _RPSToChar(1);
    }else{
        number_moves++;
        return _RPSToChar(2);       // 0 and 2
    }
}
//Destructors
RPS_AI_Two::~RPS_AI_Two(){

}