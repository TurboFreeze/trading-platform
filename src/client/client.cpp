#include <sys/socket.h>
#include <netdb.h>
#include <iostream>

int main (void) {
        char* destination = "localhost";
        char* port = "102";
        struct addrinfo hints;
        struct addrinfo *res;

        // struct setup
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        if (getaddrinfo(destination, port, &hints, &res)) {
                perror("could not get info");
                return 1;
        }

        return 0;
}
