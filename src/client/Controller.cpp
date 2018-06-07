#include "Controller.h"
#include "View.h"

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
        }
}
