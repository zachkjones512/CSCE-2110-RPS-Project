class RPS_AI_One{
    public:
    //Constructors
        RPS_AI_One();
    //Mutators
        void BalanceWeights(int last_move, int move_before_last);
    //Accessors
        int ChooseMove(int last_move);
    //Destructors
        ~RPS_AI_One();
    private:
        float** weights;
        int* moves_from_node;
        int last_move;
        int move_before_last;
        int number_moves;
};