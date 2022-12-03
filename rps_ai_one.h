//
//
//  Written by: Caleb Smay
//
//

class RPS_AI_One{
    public:
    //Constructors
        RPS_AI_One();
    //Mutators
        void _BalanceWeights(int last_move, int move_before_last);
        int _CharToRPS(char input);
        char _RPSToChar(int input);
    //Accessors
        char ChooseMove(char recent_move);
    //Destructors
        ~RPS_AI_One();
    private:
        float** weights;
        int* moves_from_node;
        int last_move;
        int move_before_last;
        int number_moves;
};