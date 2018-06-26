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

// print error message
void View::error(std::string message) {
        std::cout << "ERROR: " << message << std::endl;
}

// general input reader
std::string View::get_input() {
        std::string s;
        std::getline(std::cin, s);
        return s;
}

// custom prompt input reader for doubles
double View::get_input_double(std::string prompt) {
        std::string s;
        bool valid;
        clear();
        std::cout << prompt;
        // loop until valid input
        do {
                std::getline(std::cin, s);
                valid = true; // TODO: validate numerical input
                if (valid) {
                        return std::stod(s);
                }
                clear();
                std::cout << "Invalid input; please try again: ";
        } while (!valid);
        return -1;
}


// custom prompt input reader
int View::get_input_int(std::string prompt) {
        std::string s;
        bool valid;
        clear();
        std::cout << prompt;
        // loop until valid input
        do {
                std::getline(std::cin, s);
                valid = true; // TODO: validate numerical input
                if (valid) {
                        return std::stoi(s);
                }
                clear();
                std::cout << "Invalid input; please try again: ";
        } while (!valid);
        return -1;
}

// custom options and prompt input reader
int View::get_option(std::string prompt, std::vector<int> options) {
        std::string s;
        int num;
        bool valid;
        clear();
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
                if (valid) {
                        return num;
                }
                clear();
                std::cout << "Invalid input; please try again: ";
        } while(!valid);
        return -1;
}

void View::clear() {
        system("clear");
        welcome();
}
