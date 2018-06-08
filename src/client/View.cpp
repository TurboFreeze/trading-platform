#include "View.h"
#include <string>
#include <iostream>

void View::welcome() {
        std::cout << "WELCOME TO THE TRADING PLATFORM - TRADE WITH US" << std::endl;
}

View::View() {
        welcome();
}

std::string View::get_input() {
        std::string s;
        std::getline(std::cin, s);
        return s;
}
