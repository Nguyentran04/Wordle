#ifndef PRINTKEY_H
#define PRINTKEY_H
#include <iostream>
#include <string>
using namespace std;
#define RESET "\033[0m"
void print(string& top_row, string& middle_row, string& bottom_row){
    cout << top_row << RESET << endl; 
    cout << middle_row << RESET << endl;
    cout << bottom_row << RESET << endl;

}

#endif