#include "Ask.h"

Ask::Ask(double p, int i) {
        price = p;
        item = i;
}

double Ask::getPrice() {
        return price;
}

int Ask::getItem() {
        return item;
}
