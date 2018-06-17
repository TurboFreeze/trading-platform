#include "Connection.h"
#include "../Constants.h"
#include <iostream>
#include <sys/socket.h>

Connection::Connection(int connection) {
        socket = connection;
}


double Connection::read_stream_double() {

        double data;

        while (true) {
                int status = recv(socket, &data, sizeof(data), 0);
                // no input received
                if (status == 0) {
                        continue;
                }
                // connection timed-out
                if (status == -1) {
                        std::cout << "Connection disconnected for file descriptor " << socket << std::endl;
                        return -1;
                }
                return data;
        }
}

int Connection::read_stream_int() {

        int data;

        while (true) {
                int status = recv(socket, &data, sizeof(data), 0);
                // no input received
                if (status == 0) {
                        continue;
                }
                // connection timed-out
                if (status == -1) {
                        std::cout << "Connection disconnected for file descriptor " << socket << std::endl;
                        return -1;
                }
                return data;
        }
}

void Connection::get_bid() {
        int item = read_stream_int();
        double price = read_stream_double();
        std::cout << "ITEM: " << item << std::endl << "PRICE: " << price << std::endl;
}

void Connection::option_handle(int option) {
        switch(option) {
        case Constants::SUBMIT_BID:
                get_bid();
                break;
        default:
                std::cout << "ERROR: UNRECOGNIZED OPTION" << std::endl;
        }
}

void Connection::start() {
        std::cout << "Connection established; the file descriptor for this connection is " << socket << std::endl;
        // continuous loop for listening
        while (true) {
                option_handle(read_stream_int());
        }
}
