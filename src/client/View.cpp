#include "View.h"
#include <string>
#include <iostream>


// constructor
View::View() {
        welcome();
}

// print the welcome message
void View::welcome() {
        std::cout << "WELCOME TO THE TRADING PLATFORM - TRADE WITH US" << std::endl;
}

// general input reader
std::string View::get_input() {
        std::string s;
        std::getline(std::cin, s);
        return s;
}

// custom options and prompt input reader
int View::get_input(std::string prompt, std::vector<int> options) {
        std::string s;
        int num = -1;
        bool valid;
        std::cout << prompt;
        // loop until valid input
        do {
                std::getline(std::cin, s);
                num = atoi(s.c_str());
                valid = false;
                // check if one of valid options
                for (int i = 0; i < options.size(); i++) {
                        if (options[i] == num) {
                                valid = true;
                                break;
                        }
                }
                if (!valid) {
                        std::cout << "Invalid input; please try again: ";
                }
        } while(!valid);
        return num;
}
