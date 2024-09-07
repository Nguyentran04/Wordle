#ifndef PLAYSTATUS_H 
#define PLAYSTATUS_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
//handling the keyboard
void status_update(string& game_stats){
    fstream update_file; 
    update_file.open("playstatus.txt", std::ios::out);
    if(update_file.is_open()){
        update_file << game_stats << endl; 
    }
    else{
        cerr << "File cannot be open!" << endl;
    }
    update_file.close(); 
}

void keyboard_color(char& letter, string& color){
    ofstream color_update; 
    color_update.open("keyboardcolor.txt", std::ios::app);
    if(color_update.is_open()){
        color_update << letter << "," << color << endl; 
    }
    else{
        cerr << "File cannot be open!" << endl; 
    }
    color_update.close();
}

void clear_status(){
    ofstream file; 
    file.open("keyboardcolor.txt", std::ios::out); 
    if(file.is_open()){
        file.close();
    }
}

#endif