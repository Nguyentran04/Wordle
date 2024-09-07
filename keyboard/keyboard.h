#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "checkmatch.h"
using namespace std;
struct Variables{
    vector<string> letters; 
    vector<string> color; 
    unordered_map<char, string>myMap; 
    unordered_map<string, string> color_pair; 
    string top, middle, bottom; 
    Variables() : top(""), middle(""), bottom("") {}

};
void keyboard_update(){
    Variables v; 
    string line, token, row1, row2, row3;
    fstream color_file; 
    row1 = "QWERTYUIOP"; 
    row2 = "ASDFGHJKL"; 
    row3 = "ZXCVBNM";
    // add the colors and its corresponding code
    v.color_pair["green"] = "\033[32m"; 
    v.color_pair["yellow"] = "\033[33m";
    v.color_pair["grey"] = "\033[90m";
    v.color_pair["RESET"] = "\033[0m";
    color_file.open("../game/keyboardcolor.txt", std::ios::in); 
    if(color_file.is_open()){
        while(getline(color_file, line)){
            stringstream ss(line); 
            getline(ss, token, ','); 
                v.letters.push_back(token); 
            getline(ss, token, ',');
                v.color.push_back(token);
            
        }
    }
    else{
        cerr << "Cannot open file!" << endl; 
    }
    for(int i = 0; i < v.letters.size(); i++){
        v.myMap[v.letters[i][0]] = v.color[i];
    }
    //first check if any of the letters in the first row is myMap.
    //create another header_file
    check_match(v.myMap, v.color_pair, row1);
    check_match(v.myMap, v.color_pair, row2);
    check_match(v.myMap, v.color_pair, row3);
    v.myMap.clear(); 
    v.letters.clear(); 
    v.color_pair.clear();
    v.color.clear(); 


}
#endif