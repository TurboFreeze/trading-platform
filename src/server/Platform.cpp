#include "Platform.h"
#include <iostream>

Platform::Platform() {
        bids = std::vector<Bid>();
}

void Platform::run() {
        bids.push_back(Bid(5, 4));
        std::cout << "Price: " << bids[0].price << std::endl;
}
