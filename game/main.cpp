#include<iostream>
using namespace std; 
#include "menu.h"
#include "tutorial.h"
#include "play.h"
#include "stats.h"
#include "print.h"
#include "playstatus.h"
#include "playstatus.h"
// create a main function. option 1: how to play game, 2 = play game, option 3: stats summary, option 4 stats reset, 5 exit the game

int main(int argc, char*argv[]){
    clear_status();
    string game_status;
    int option_num; 
    //updating the status of the game
    game_status = "WAITING"; 
    status_update(game_status); 
    system("clear"); 
    menu(); 
    while(cin >> option_num && option_num != 5){//
        if(option_num == 1){ // display the menu
            game_status = "WAITING"; 
            status_update(game_status);
            system("clear");
            tutorial_display();
        }
        if(option_num == 2){
            system("clear");
            game_status = "PLAYING";
            status_update(game_status); 
            play_function();
            
        }
        if(option_num == 3){
            print_stats();
        }
        if(option_num == 4){
            stats_reset();
        }
    }
        if(option_num == 5){
            game_status = "EXIT"; 
            status_update(game_status); 
        }

}
