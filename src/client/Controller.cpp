#include "Controller.h"
#include "View.h"
#include "../Constants.h"
#include <sys/socket.h>

Controller::Controller(int connection) {
        socket = connection;
}

void Controller::start() {
        // launch view for the user interface
        View v = View();

        // main loop interfacing with client-side user
        while (true) {
                // get input and process
                std::string result = v.get_input();
                char result_chars[HEADER_LENGTH];
                strcpy(result_chars, result.c_str());
                // send to server
                send(socket, result_chars, HEADER_LENGTH, 0);
        }
}
