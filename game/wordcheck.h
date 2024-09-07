#ifndef WORDCHECK_H
#define WORDCHECK_H
#include <iostream>
#include <fstream>
using namespace std;

bool word_validity(string& word){
    fstream valid_input; 
    string line;
    vector<string> word_list;
    valid_input.open("allowed.txt", std::ios::in); 
    if(valid_input.is_open()){
        while(getline(valid_input, line)){
            word_list.push_back(line);
        }
    }
    else{
        cerr << "Cannot open allowed.txt file!" << endl;
    }
    valid_input.close();
    string line2;
    fstream valid2; 
    valid2.open("words.txt", std::ios::in); 
    if(valid2.is_open()){
        while(getline(valid2, line2)){
            word_list.push_back(line2);
        }
    }
    else{
        cerr << "Cannot open words.txt file!" << endl;
    }
    valid_input.close();

    for(int x = 0; x < word_list.size(); x++){
        if(word == word_list[x]){
            return true;
        }
    }
    return false; 
}

#endif 