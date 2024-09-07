#ifndef PRINT_H 
#define PRINT_H
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
#include "menu.h"
using namespace std; 

void print_stats(){

    float percentage = 0.00, attempt;
    int average_attempts = 0, game_play = 0, correct = 0, total_attempts = 0, current_streak = 0, longest_streak = 0; 
    int index = 0, index2 = 0;
    string line, token, token2, line2; 
    fstream stats_out; 
    vector<int> attempts_each; 
    vector<string> word_list; 
    vector<string> status_list;
    stats_out.open("stats.txt", std::ios::in); 

    while (getline(stats_out, line2)) {
        stringstream ss2(line2);
        string token2;
        while (getline(ss2, token2, ',')) {
            switch(index2){
                case(0):
                total_attempts = stoi(token2); 
                case(1): 
                game_play = stoi(token2); 
                case(2): 
                correct = stoi(token2); 
                default:
                break;
            }
            index2 ++;
        }
    }

    fstream stats2; 
    stats2.open("stats2.txt", std::ios::in); 
    if(stats2.is_open()){
        while(getline(stats2, line)){
            stringstream ss(line); 
            getline(ss, token, ',');
            word_list.push_back(token); 
            getline(ss, token, ','); 
            status_list.push_back(token); 
            getline(ss, token, ','); 
            attempts_each.push_back(stoi(token));
        }
    }
    stats2.close();
    current_streak = 0;
    correct = 0;
    for(int x = 0; x < status_list.size(); x ++){
        if(status_list[x] == "YES"){
            correct ++;
        }
        if(x != status_list.size() - 1){
            if(status_list[x] == "YES" && status_list[x + 1] == "YES"){
                current_streak ++; 
                if(current_streak > longest_streak){
                    longest_streak = current_streak;
                }
            }
        else{
                current_streak = 0;
                if(current_streak > longest_streak){
                    longest_streak = current_streak;
                }
            }
        }
    }
    if(game_play == 0){
        percentage = 0.00; 
    }
    else{
        percentage = (correct / float(game_play)) * 100;
    }
    average_attempts = total_attempts / game_play;
    system("clear");
    cout << "==============================" << endl; 
    cout << "         STATS SUMMARY        " << endl; 
    cout << "==============================" << endl; 
    cout << "Time played:" << std::setw(16) << std::right << game_play << endl; 
    cout << "Average Attempts:" << std::setw(11) << std::right << average_attempts << endl; 
    cout << "Current streak:" << std::setw(13) << std::right << current_streak << endl; 
    cout << "Longest streak:" << std::setw(13) << std::right << longest_streak << endl; 
    cout << "Win Percentage:" << std::setw(14) << std::right <<std::fixed << std::setprecision(2) << percentage << "%" <<  endl << endl; 
    cout << "------------------------------" << endl; 
    cout << "WORD       ATTEMPTS        WIN" << endl; 
    cout << "------------------------------" << endl; 
    
    for(int i = 0; i < status_list.size(); i++){
        cout << word_list[i] << std::setw(14) << std::right << attempts_each[i] << std::setw(11) << std::right << status_list[i] << endl;
    }
    
    cout << endl;
    cin.ignore(); 
    cout << "   Press [enter] to continue   " << endl; 
    cin.ignore(); 
    system("clear");
    menu(); 
    
}


#endif