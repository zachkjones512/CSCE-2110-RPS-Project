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
                if(printMessage)
                    std::cout << "Player 1 wins." << std::endl << std::endl;
                return 1;
            }else{
                if(printMessage)
                    std::cout << "Player 2 wins." << std::endl << std::endl;
                return 2;
            }
        }else{
            if(playerOne - playerTwo == 1){
                if(printMessage)
                    std::cout << "Player 2 wins." << std::endl << std::endl;
                return 2;
            }else{
                if(printMessage)
                    std::cout << "Player 1 wins." << std::endl << std::endl;
                return 1;
            }
        }
    }else{
        std::cout << "INVALID INPUT " << playerOne << " " << playerTwo << std::endl;
    }

    return 0;
}
void RPS_Analysis(int num_rounds, int player_1_wins, int ties){ //TODO: Finish analysis function
    int player_1_losses = num_rounds - (player_1_wins + ties);
    
    if(player_1_wins > player_1_losses){
        std::cout << "Winning Algorithm: agent1" << std::endl;
        std::cout << "Win Percentage: " << player_1_wins / num_rounds << std::endl;
        std::cout << "Tie Percentage: " << ties / num_rounds << std::endl << std::endl;

        std::cout << "Losing Algorithm: agent2" << std::endl;
        std::cout << "Win Percentage: " << player_1_losses / num_rounds << std::endl;
        std::cout << "Tie Percentage: " << ties / num_rounds << std::endl;
    }else{
        std::cout << "Winning Algorithm: agent2" << std::endl;
        std::cout << "Win Percentage: " << player_1_losses / num_rounds << std::endl;
        std::cout << "Tie Percentage: " << ties / num_rounds << std::endl << std::endl;

        std::cout << "Winning Algorithm: agent1" << std::endl;
        std::cout << "Win Percentage: " << player_1_wins / num_rounds << std::endl;
        std::cout << "Tie Percentage: " << ties / num_rounds << std::endl;
    }
}
void RPS_Status(int current_round, int num_rounds, int player_1_wins, int ties, int times_to_display){
    if(current_round % (int)(num_rounds / times_to_display) == 0){
        int player_1_losses = num_rounds - (player_1_wins + ties);
        std::cout << "Round " << num_rounds << std::endl;
        std::cout << "Win: " << player_1_wins << ", " << (float)(player_1_wins / num_rounds) * 100 << std::endl;
        std::cout << "Tie: " << ties << ", " << (float)(ties / num_rounds) * 100 << std::endl;
        std::cout << "Loss: " << player_1_losses << ", " << (float)(player_1_losses / num_rounds) * 100 << std::endl;
    }   
}

int main(){
    int num_rounds = 10;

    int player_1_wins = 0, ties = 0;
    char player_1_choice = '|', player_2_choice = '|', player_1_previous_choice = '|';

    //INITIALIZE AGENT ONE
    //INITIALIZE AGENT TWO

    std::cout << "Enter in number of rounds: ";
    std::cin >> num_rounds;
    std::cout << "Enter the number of times the current score should be printed: ";
    int times_to_display = 0;
    std::cin >> times_to_display;
    if(times_to_display > num_rounds)
        times_to_display = num_rounds;

    for(int i = 0; i < num_rounds; i++){
        
        player_1_previous_choice = player_1_choice;
        //player_1_choice = agent1.ChooseMove(player_2_choice);
        //player_2_choice = agent2.ChooseMove(player_1_previous_choice);

        int result = RPS_Judge(player_1_choice, player_2_choice, false);
        RPS_Status(i, num_rounds, player_1_wins, ties, times_to_display);
        
        if(result == 0){
            ties++;
        }else if(result == 1){
            player_1_wins++;
        }
    }

    RPS_Analysis(num_rounds, player_1_wins, ties);

    return 0;
}