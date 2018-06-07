#include "Controller.h"
#include <sys/socket.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>

int main (void) {
        int socketfd;
        char* destination = "localhost";
        char* port = "102";
        struct addrinfo hints;
        struct addrinfo *res;
        struct addrinfo *result;

        std::cout << "Attempting to reach server..." << std::endl;

        // struct setup
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        if (getaddrinfo(destination, port, &hints, &res)) {
                perror("could not get info");
                return 1;
        }

        // loop through for first possible result

        for (result = res; result != NULL; result = result->ai_next) {
                if ((socketfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol)) == -1) {
                        perror("socket failure");
                        return 1;
                }

                // attempt to make the connection
                if (connect(socketfd, result->ai_addr, result->ai_addrlen) == -1) {
                        close(socketfd);
                        perror("connection");
                        continue;
                }
                break;
        }

        // finish connecting by freeing up and checking for success
        freeaddrinfo(res);
        if (result == NULL) {
                perror("connection failed");
                return 1;
        }

        std::cout << "Connected to server" << std::endl;

        // launch controller
        Controller controller = Controller(socketfd);
        controller.start();

        return 0;
}
