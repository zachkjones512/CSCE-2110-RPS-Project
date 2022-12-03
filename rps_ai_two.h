//
//
//  Written by: Caleb Smay
//
//

class RPS_AI_Two{
    public:
    //Constructors
        RPS_AI_Two();
    //Mutators
        int _CharToRPS(char input);
        char _RPSToChar(int input);
    //Accessors
        char ChooseMove(char recent_move);
    //Destructors
        ~RPS_AI_Two();
    private:
        int last_move;
        int move_before_last;
        int number_moves;
};