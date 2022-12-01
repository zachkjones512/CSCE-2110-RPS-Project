/*  Name: Daniel Kaderli
    Date: 11/30/22
    Program: RPS Frequency Algorithm
    Description: Algorith that uses the frequency of the opponents 
    previous moves to predict the most likely move and counter it.
    Variables: 
        - rockSum, paperSum, scissorSum:
            These integers are used to keep track of the number
            of times the opponent uses each move. They are used
            to calculate the frequencies of each move.
        - rockFreq, paperFreq, scissorFreq:
            These floats are used to keep track of the frequency
            of each move used by the opponent. They are calculated
            by dividing the corresponding move's sum by the total
            number of moves.
    
    Functions:
        - SelectRand()
            This function selects a random move. It's called
            whenever the previous move is invalid or the 
            frequencies are all equal.
        
        - PrintStats()
            Debugging function that prints out the sums and 
            frequencies of each move.
        
        - FrequencyFinder()
            Adds the previous move to the sum variable of its
            move. Then it gets the frequency by dividing the
            sum from the total number of moves.
        
        - ChooseMove()
            This function checks to see if the move is valid
            then adds it to the list and calls the
            FrequencyFinder Function to choose the move.

    Notes to self:
        Add simple algorithms to debug against


*/

#include "drkFreq.h"

// Function for selecting random move
char Frequency::SelectRand(){
    int randMove = rand() % 3; // random num between 0 and 2
    switch(randMove){
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

// function to print stats for debugging
void Frequency::PrintStats(){
    cout << "Sums" << endl;
    cout << "Rock: " << rockSum << endl;
    cout << "Paper: " << paperSum << endl;
    cout << "Scissors: " << scissorSum << endl;

    cout << "Frequencies" << endl;
    cout << "Rock: " << rockFreq << endl;
    cout << "Paper: " << paperFreq << endl;
    cout << "Scissors: " << scissorFreq << endl;
}  

// function that calculates the frequencies of each move
void Frequency::FrequencyFinder(char prevMove){

    //cout << moves << endl;
     

        // increases sum variables
    switch(prevMove){
        case 'R':
            rockSum++;
            break;
        
        case 'P':
            paperSum++;
            break;

        case 'S':
            scissorSum++;
            break;
        
        default:
            cout << "invalid move" << endl;
            break;
    }



    // gets frequency of each moves occurance
    rockFreq = ((float)rockSum/(float)moves.length());
    paperFreq = ((float)paperSum/(float)moves.length());
    scissorFreq = ((float)scissorSum/(float)moves.length());

}

// function that chooses move based on frequencies
char Frequency::ChooseMove(char prevMove){

    // prevents | from being added to moves
    if(prevMove == '|'){
        return SelectRand();
    }else{ 
        moves += prevMove; // adds each move to the list
        FrequencyFinder(prevMove); // finds frequencies
    }
    
    // decides which move to choose based on previous frequencies
    if(rockFreq > paperFreq && rockFreq > scissorFreq){
        return 'P';
    }

    if(paperFreq > rockFreq && paperFreq > scissorFreq){
        return 'S';
    }

    if(scissorFreq > paperFreq && scissorFreq > rockFreq){
        return 'R';
    }
  
    return SelectRand();
}