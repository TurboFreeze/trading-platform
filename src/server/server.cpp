// #include "Platform.h"
#include "Connection.h"
#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <vector>

void create_connection (int connection, Platform* platform) {
        // create new connection and start it up
        Connection c = Connection(connection, platform);
        c.start();
}

int main (void) {
        int socketfd, connection;
        int opt = 1;
        char* port = "102";
        int num_connections = 10;
        struct addrinfo hints;
        struct addrinfo *res;
        struct addrinfo *result;
        struct sockaddr_in address;
        socklen_t addrsize;
        std::vector<std::thread> connections = std::vector<std::thread>();

        // struct setup
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;
        if (getaddrinfo(NULL, port, &hints, &res)) {
                perror("could not get info");
                return 1;
        }

        // loop through for first possible result

        for (result = res; result != NULL; result = result->ai_next) {
                if ((socketfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol)) == -1) {
                        perror ("socket failure");
                        continue;
                }

                if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
                        perror("setsockopt");
                        return 1;
                }

                // binding to the port
                if (bind(socketfd, result->ai_addr, result->ai_addrlen) == -1) {
                        close(socketfd);
                        perror ("bind");
                        continue;
                }
                break;
        }

        // finish binding by freeing up and checking for success
        freeaddrinfo(res);
        if (result == NULL) {
                perror("bind failed");
                return 1;
        }

        // start listening
        if (listen (socketfd, num_connections) == -1) {
                perror ("listen failed");
                return 1;
        }


        std::cout << "Order management system platform created" << std::endl;
        Platform p = Platform();

        std::cout << "Waiting for connections..." << std::endl;

        // main loop for accepting and processing connections
        while (true) {
                // accept a connection
                addrsize = sizeof address;
                connection = accept (socketfd, (struct sockaddr *) &address, &addrsize);
                if (connection == -1) {
                        perror("connection could not be accepted");
                        continue;
                }
                std::cout << "Connection accepted" << std::endl;
                // multithreading; spin off thread with the new connection
                connections.push_back(std::thread(create_connection, connection, &p));
        }

        // joining threads back into main launch thread
        for (int i = 0; i < connections.size(); i++) {
                connections[i].join();
        }
        return 0;
}
