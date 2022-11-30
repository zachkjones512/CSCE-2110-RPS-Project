#include <iostream>
#include <string>
#include "rps_manual.h"
char ManualInput(){
    std::cout << "Please enter the player's move:" << std::endl;
    while(true){
        std::string input;
        std::getline(std::cin, input);
        try{
            if(input.at(0) == 'R' || input.at(0) == 'P' || input.at(0) == 'S'){
                return input.at(0);
            }else{
                std::cout << "Not a valid move!" << std::endl;
            }
        }
        catch(std::out_of_range){
            std::cout << "Not a valid move!" << std::endl;
        }
    }
    return ' ';
}