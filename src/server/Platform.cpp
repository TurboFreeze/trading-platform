#include "Platform.h"
#include <iostream>

Platform::Platform() {
        bids = std::vector<Bid>();
}

void Platform::addBid(int sender, Bid b) {
        bids.push_back(b);
        printAll();
}

void Platform::addAsk(int sender, Ask a) {
        asks.push_back(a);
        printAll();
}

void Platform::printAll() {
        clear();
        std::cout << "BIDS" << std::endl;
        std::cout << "PRICE\tITEM" << std::endl;
        for(int i = 0; i < bids.size(); i++) {
                std::cout << bids[i].getPrice() << "\t" << bids[i].getItem() << std::endl;
        }

        std::cout << "\n\n\n";

        std::cout << "ASKS" << std::endl;
        std::cout << "PRICE\tITEM" << std::endl;
        for(int i = 0; i < asks.size(); i++) {
                std::cout << asks[i].getPrice() << "\t" << asks[i].getItem() << std::endl;
        }
}

void Platform::clear() {
        system("clear");
}
