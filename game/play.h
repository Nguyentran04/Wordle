#ifndef PLAY_H 
#define PLAY_H 
#include <iostream>
#include <iomanip>
#include <fstream> // this is for opening/reading the files
#include <vector> // use vectors so dont have to worry about constantly updating
#include <cstdlib>
#include <algorithm>
#include "menu.h"
#include "stats.h"
#include "wordcheck.h"
using namespace std; 
#include <sstream> //this is use to deal with files. 
#define GREEN "\033[32m" // correct letter in the correct position
#define RESET "\033[0m" // make the color back to original (white)
#define YELLOW "\033[33m" // correct letter but wrong placement
#define GREY "\033[90m" // letter not in the word
#include "playstatus.h"
//declaring the colors that will be use in the program 

struct Variables{ // use a struct to store variables to the game
    int total_play; 
    string top, middle, bottom, status; 
    //initialize the scores by first writing them in the file
    float percentage; 
    Variables(){
        total_play = 0; // initialize everything to 0 at the beginning of the program
        status = ""; 
        top = ""; 
        middle = "";
        bottom = "";

    }
    

};

void play_function(){
    //opening files words.txt for reading and for retrieving the daily words
    clear_status();
    string color; 
    Variables v; 
    int guesses = 0; // initialize the guesses to be at 0;
    vector<string> possible_words; 
    fstream word_file; 
    string word_day, word_input, letter_display; 
    //to write the display screen into message.txt
    ofstream outputfile; 
    outputfile.open("message.txt"); 
    bool check;
    string line; // use for retrieving the letters at each line from the txt file. 
    word_file.open("words.txt", ios::in);
    if(word_file.is_open()){
        while(getline(word_file, line)){
            possible_words.push_back(line); 
        }
    //after accessing the words, need to close the file
    word_file.close(); 
    }
    //to get random words
    srand(time(0));
    word_day = possible_words[rand() % possible_words.size()]; 
    system("clear"); 
    // converting the words in the txt file into all lowercase
    for(int i = 0; i < word_day.length(); i++){
        word_day[i] = tolower(word_day[i]);
    }
    // run the program until the player runs out the number of guesses. 
    while(guesses <=5){
        cout << "Enter guess: ";
        cin >> word_input; 
        cout << endl;

        //coverting the input into all lower case.
        for(int x = 0; x < word_input.length(); x++){
            word_input[x] = tolower(word_input[x]); 
        } 

        bool valid = word_validity(word_input);
        if(!valid){
            cout << "Reneter a valid word!" << endl;
        }
        else if(word_input.length()!= 5){
            std::cout << endl; 
            std::cout << "Please enter a 5 letters word!" << endl; 
        }
            else{
            if(word_input == word_day){
            for(int x = 0; x < word_input.length(); x++){
                letter_display += GREEN + string(1, word_input[x]) + RESET;
                v.top += string(GREEN); 
                v.middle += string(GREEN); 
                v.bottom += string(GREEN); 
                v.top += " --- ";
                v.middle += "| ";
                v.middle += word_input[x]; 
                v.middle += " |";
                v.bottom += " --- ";
                color = "green";
                keyboard_color(word_input[x], color);
                
            }
            guesses++;
            std::cout << v.top << RESET << endl;
            std::cout << v.middle << RESET << endl;
            std::cout << v.bottom << RESET << endl;
            outputfile << v.top << RESET << endl;
            outputfile << v.middle << RESET << endl; 
            outputfile << v.bottom << RESET << endl;
            break;
            }
            else{
                for(int i = 0; i < word_input.length(); i ++){
                    if(word_day.find(word_input[i]) != std::string::npos){
                         if(word_input[i]== word_day[i]){
                        //formatting the matched character
                        letter_display += GREEN + string(1, word_input[i]) + RESET;
                        v.top += string(GREEN); 
                        v.middle += string(GREEN); 
                        v.bottom += string(GREEN); 
                        v.top += " --- ";
                        v.middle += "| ";
                        v.middle += word_input[i]; 
                        v.middle += " |";
                        v.bottom += " --- ";
                        color = "green"; 
                        keyboard_color(word_input[i], color); 

                    }
                    else{
                        letter_display += YELLOW+ string(1, word_input[i]) + RESET;
                        v.top += string(YELLOW); 
                        v.middle += string(YELLOW); 
                        v.bottom += string(YELLOW); 
                        v.top += " --- ";
                        v.middle += "| ";
                        v.middle += word_input[i]; 
                        v.middle += " |";
                        v.bottom += " --- ";
                        color = "yellow";
                        keyboard_color(word_input[i], color);

                }
            }
            else{
                    letter_display += GREY+ string(1, word_input[i]) + RESET;
                    v.top += string(GREY); 
                    v.middle += string(GREY); 
                    v.bottom += string(GREY); 
                    v.top += " --- ";
                    v.middle += "| ";
                    v.middle += word_input[i]; 
                    v.middle += " |";
                    v.bottom += " --- ";
                    color = "grey"; 
                    keyboard_color(word_input[i], color); 
            }
            //want a case for if the letter appears twice 
        }
        std::cout << v.top << RESET << endl;
        std::cout << v.middle << RESET << endl;
        std::cout << v.bottom << RESET << endl;
        if(outputfile.is_open()){
            outputfile << v.top << RESET << endl;
            outputfile << v.middle << RESET << endl; 
            outputfile << v.bottom << RESET << endl;
        }
        v.top = ""; 
        v.middle = ""; 
        v.bottom = "";
        guesses ++;
    }
    }
        //print the stuff out
    }
    fstream output;
    output.open("message.txt");
    
    cout << endl; 
    if(guesses <= 6 && word_input == word_day){
        system("clear");
        while(getline(output, line)){
            cout << line << endl;
        }
        cout << std::setw(14) << std::right << "    Correct!" << endl;
        cout << std::setw(14) << std:: right << " The word is " << word_day << "!" << endl; 
        v.status = "YES";
        v.total_play ++;
        outputfile.clear(); 
    }
    else{
        v.total_play ++;
        system("clear"); 
        while(getline(output, line)){
            cout << line << endl;
        }
        cout << "\nBetter luck next time!" << endl; 
        cout << "The word is " << word_day << endl; 
        v.status = "NO";
        outputfile.clear(); 
        }

    // put status and word in another file
     ofstream stats2; 
     stats2.open("stats2.txt", std::ios::app); 
     if(stats2.is_open()){
        stats2 << word_day << "," << v.status << "," << guesses << endl;
     }
     stats2.close();
    
    // take the guesses, correct guess and word_day for stats
    stat_calculation(guesses, v.total_play);
    cin.ignore(); 
    cout << "Press [enter] to continue" << endl;
    cin.ignore(); 
    system("clear");
    menu();
    output.close();
    outputfile.close();
    }
    


#endif