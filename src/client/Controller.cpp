#include "Controller.h"
#include <iostream>
#include <thread>
#include <chrono>

Controller::Controller(int connection) {
        socket = connection;
}

void Controller::start() {
        // main loop interfacing with client-side user
        while (true) {
                // get input and process
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Waiting for input" << std::endl;
        }
}
