#include <cstdlib>
#include <iostream>
#include "rps_ai_one.h"

//Constructors
    RPS_AI_One::RPS_AI_One(){
        //Initialize array of weights for the various outcomes
        this->weights = new float*[3];
        for(int i = 0; i < 3; i++){
            this->weights[i] = new float[3];
            for(int j = 0; j < 3; j++){
                this->weights[i][j] = 1.0 / 3.0;    //Set each cell to an equal chance
            }
        }
        
        //Initialize array to keep track of the number of moves from each node
        this->moves_from_node = new int[3];
        for(int i = 0; i < 3; i++){
            this->moves_from_node[i] = 1;
        }

        last_move = 4;
        move_before_last = 4;
    }
//Mutators
    //Updates the chances a certain move will be taken
    void RPS_AI_One::_BalanceWeights(int last_move, int move_before_last){
        //Checks if there have been enough moves to start predicting
        if(move_before_last <=2 && move_before_last >=0){
            
            this->moves_from_node[move_before_last]++;

            //DEBUG std::cout << "move_before_last: " << _RPSToChar(move_before_last) << std::endl << "last_move: " << _RPSToChar(last_move) << std::endl;
            for(int i = 0; i < 3; i++){
                
                float value = this->weights[move_before_last][i];
                //DEBUG std::cout << "value: " << value << std::endl;
                if(i == last_move){
                    //DEBUG std::cout << "original value: " << this->weights[move_before_last][i] << std::endl;
                    this->weights[move_before_last][i] = ((value * moves_from_node[move_before_last]) + 1) / (moves_from_node[move_before_last] + 1);
                }else{
                    this->weights[move_before_last][i] = ((value * moves_from_node[move_before_last]) + 0) / (moves_from_node[move_before_last] + 1);
                }
                //DEBUG std::cout << "new value: " << this->weights[move_before_last][i] << std::endl;
                 
            }
            //DEBUG
            // std::cout << "Chances for " << _RPSToChar(move_before_last) << ":" << std::endl;
            // for(int i = 0; i < 3; i++){
            //     std::cout << _RPSToChar(i) << ": " << this->weights[move_before_last][i] << " ";
            // }
            //END DEBUG
        }
    }
    int RPS_AI_One::_CharToRPS(char input){
        //Had to do this as my original program was designed with numbers representing the options
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
    char RPS_AI_One::_RPSToChar(int input){
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
    char RPS_AI_One::ChooseMove(char recent_move){
        int last_move = _CharToRPS(recent_move);
        this->move_before_last = this->last_move;
        this->last_move = last_move;
        _BalanceWeights(this->last_move, this->move_before_last);
        

        if(move_before_last == 4 || last_move == 4){
            return _RPSToChar(rand() % 3);
        }else{
            //Find the most likely move
            int moveindex = 0;
            for(int i = 0; i < 3; i++){
                if(this->weights[last_move][i] > this->weights[last_move][moveindex]){
                    moveindex = i;
                }
            }
            //DEBUG std::cout << "Predicted move: " << _RPSToChar(moveindex) << " Counter: " << _RPSToChar((moveindex + 2) % 3) << std::endl;
            return _RPSToChar((moveindex + 2) % 3);
        }
        return 'P';
    }
//Destructors
    RPS_AI_One::~RPS_AI_One(){}


/*
    float** weights;
    int* moves_from_node;
    int last_move;
    int move_before_last;
    int number_moves;
*/