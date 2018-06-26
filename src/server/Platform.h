#include "Bid.h"
#include <vector>

class Platform {
public:
Platform();
void addBid(int sender, Bid b);
void printBids();
void clear();
private:
std::vector<Bid> bids;
};
