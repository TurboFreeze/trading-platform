#include "Bid.h"

Bid::Bid(double p, int i) {
        price = p;
        item = i;
}

double Bid::getPrice() {
        return price;
}

int Bid::getItem() {
        return item;
}
