#include "Controller.h"
#include "../Constants.h"
#include <sys/socket.h>

Controller::Controller(int connection) {
        // set connection to server
        socket = connection;

        // launch view for the user interface
        v = View();
}

void Controller::submit_bid() {
        double price = v.get_input("Price of the bid: ");

        // send to server
        send(socket, &price, sizeof(price), 0);
}

void Controller::send_message() {
        std::string result = v.get_input();
        char result_chars[Constants::HEADER_LENGTH];
        strcpy(result_chars, std::to_string(result).c_str());
        // send to server
        send(socket, result_chars, Constants::HEADER_LENGTH, 0);
}

void Controller::start() {

        // main loop interfacing with client-side user
        while (true) {
                // get input and process
                std::vector<int> options = {Constants::SUBMIT_BID};
                std::string prompt = "Enter an option: ";
                int result = v.get_input(prompt, options);

                // routing to appropriate processing functions
                switch (result) {
                case Constants::SUBMIT_BID:
                        submit_bid();
                        break;
                default:
                        v.error("Command not recognized");
                        continue;
                }
        }
}
