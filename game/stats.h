#ifndef STATS_H 
#define STATS_H 
#include <iostream>
using namespace std; 
#include<algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "menu.h"

struct Stat {
    int average_attempts, total_tries, try_each, game_play;
    float percentage; 
    Stat() : average_attempts(0), total_tries(0), game_play(0){}
};
void stats_reset(){
    Stat s; 
    fstream stats_output, stats2; 
    stats_output.open("stats.txt", std::ios::out);
    if(stats_output.is_open()){
        stats_output  << s.total_tries << "," << s.game_play << endl;
    }
    else{
        cerr << "Error opening stats.txt" << endl; 
    }
    stats_output.close();
    stats2.open("stats2.txt", std::ios::out); 
    if(stats2.is_open()){
        stats2.close();
    }

    system("clear");
    menu(); 


}

void stat_calculation(int& guess, int& total_play){
    vector<string> status_list; 
    vector<string> word_list;
    Stat s; // automatically called for the default constructor
    int index = 0;
    fstream stats_out; 


    stats_out.open("stats.txt", std::ios::in); 
    string line, token, line2, token2; 
    getline(stats_out, line); 
    stringstream ss(line);
    while(getline(ss, token, ',')){
        switch(index){
            case(0):
            s.total_tries = guess + stoi(token);
            break;
            case(1):
            s.game_play = total_play + stoi(token);
            break;
            default:
            break;
        }
        index++;

    }
    stats_out.close(); 


    stats_out.open("stats.txt", std::ios::out); 
    if(stats_out.is_open()){
        stats_out << s.total_tries << "," << s.game_play << endl;
    }
    else{
        cerr << "Can not open stats.txt" << endl; 
    }
    stats_out.close();

}




#endif