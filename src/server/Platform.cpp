#include "Platform.h"
#include <iostream>

Platform::Platform() {
        bids = std::vector<Bid>();
}

void Platform::addBid(int sender, Bid b) {
        bids.push_back(b);
        printBids();
}

void Platform::printBids() {
        clear();
        std::cout << "PRICE\tITEM" << std::endl;
        for(int i = 0; i < bids.size(); i++) {
                std::cout << bids[i].getPrice() << "\t" << bids[i].getItem() << std::endl;
        }
}

void Platform::clear() {
        system("clear");
}
