#include "rps_ai_one.h"

//Constructors
    RPS_AI_One::RPS_AI_One(){
        //Initialize array of weights for the various outcomes
        this->weights = new float*[3];
        for(int i = 0; i < 3; i++){
            this->weights[i] = new float[3];
            for(int j = 0; j < 3; j++){
                this->weights[i][j] = 1 / 3;    //Set each cell to an equal chance
            }
        }
        
        //Initialize array to keep track of the number of moves from each node
        this->moves_from_node = new int[3];
        for(int i = 0; i < 3; i++){
            this->moves_from_node[i] = 1;
        }
    }
//Mutators
    void RPS_AI_One::BalanceWeights(int last_move, int move_before_last){}
//Accessors
    int RPS_AI_One::ChooseMove(int last_move){
        
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