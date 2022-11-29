#include <iostream>

//Just a simple judge for Rock Paper Scissors
//Inputs must be 'R', 'P', or 'S'. Otherwise it will reject the ruling
int RPS_Judge(char playerOne, char playerTwo, bool printMessage){
    //Check if both inputs are valid
    if(printMessage){
        std::cout << "Player 1 input: " << playerOne << ", Player 2 input: " << playerTwo << std::endl;
    }

    if((playerOne == 'R' || playerOne == 'P' || playerOne == 'S') && (playerTwo == 'R' || playerTwo == 'P' || playerTwo == 'S')){
        //80, 82, 83
        //P , R , S
        //Stuff to make the decision making easier
        if(playerOne == 80)
            playerOne++;
        if(playerTwo == 80)
            playerTwo++;

        if(playerOne == playerTwo){
            if(printMessage)
                std::cout << "Tie." << std::endl << std::endl;
            return 0;
        }else if(playerTwo > playerOne){
            if(playerTwo - playerOne == 1){
                std::cout << "Player 1 wins." << std::endl << std::endl;
                return 1;
            }else{
                std::cout << "Player 2 wins." << std::endl << std::endl;
                return 2;
            }
        }else{
            if(playerOne - playerTwo == 1){
                std::cout << "Player 2 wins." << std::endl << std::endl;
                return 2;
            }else{
                std::cout << "Player 1 wins." << std::endl << std::endl;
                return 1;
            }
        }
    }else{
        std::cout << "INVALID INPUT " << playerOne << " " << playerTwo << std::endl;
    }

    return 0;
}

int main(){
    int num_rounds = 10;
    
    int player_1_wins = 0, player_2_wins = 0, ties = 0;
    char player_1_choice = '|', player_2_choice = '|';
    
    for(int i = 0; i < num_rounds; i++){
        
        //player_1_choice = AGENT ONE GOES HERE
        //player_2_choice = AGENT TWO GOES HERE

        int result = RPS_Judge(player_1_choice, player_2_choice, true);



    }

    return 0;
}