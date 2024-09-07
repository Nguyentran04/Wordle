#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "keyboard.h"

using namespace std;

int main() {
    string row1 = "QWERTYUIOP"; 
    string row2 = "ASDFGHJKL"; 
    string row3 = "ZXCVBNM";
    string current_status, line; 
    current_status = "UNKNOWN";
    fstream game_status; 
    
    while (true) {
        game_status.open("../game/playstatus.txt", ios::in); 
        if (game_status.is_open()) {
            while (getline(game_status, line)) {
                current_status = line; 
            }
             // if the status is "waiting"
            if (current_status == "WAITING") {
                system("clear"); // or use "cls" on Windows
                cout << "Waiting for the game to start...." << endl;
            } else if (current_status == "PLAYING") {
                system("clear"); // or use "cls" on Windows
                keyboard_update();

            } 
        }
        else{
            cerr << "Cannot open file!" << endl;
        }
        game_status.close();


    }
    return 0;
}
