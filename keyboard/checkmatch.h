#ifndef CHECKMATCH_H
#define CHECKMATCH_H
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "printkey.h"
using namespace std; 
struct Var{
    string top, middle, bottom; 
    Var() : top(""), middle(""), bottom("") {}
};
void check_match(unordered_map<char, string>& myMap, unordered_map<string, string>& color_pair, string& row){
    Var v;
    string display; 
    for(int i = 0; i < row.length(); i++ ){
        if(myMap.find(tolower(row[i])) != myMap.end()){
            // row[i] is the letter
            display += color_pair[myMap[tolower(row[i])]] + row[i] + color_pair["RESET"];
            v.top += color_pair[myMap[tolower(row[i])]]; 
            v.middle += color_pair[myMap[tolower(row[i])]];
            v.bottom += color_pair[myMap[tolower(row[i])]];
            v.top += " --- ";
            v.middle += "| ";
            v.middle += row[i];
            v.middle += " |";
            v.bottom += " --- ";
        }
        else{
            display += color_pair["RESET"]+ row[i] + color_pair["RESET"];
            v.top += color_pair["RESET"]; 
            v.middle += color_pair["RESET"];
            v.bottom += color_pair["RESET"];
            v.top += " --- ";
            v.middle += "| ";
            v.middle += row[i];
            v.middle += " |";
            v.bottom += " --- ";
        }
    }

 
    print(v.top, v.middle, v.bottom); 
    v.top = ""; 
    v.middle = ""; 
    v.bottom = ""; 
}

#endif