#include "Connection.h"
#include <iostream>
#include <thread>
#include <chrono>

Connection::Connection(int connection) {
        socket = connection;
}

void Connection::start() {
        std::cout << "Connection established; the file descriptor for this connection is " << socket << std::endl;
        // continuous loop for listening
        while (true) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                // logic for listening
        }
}
