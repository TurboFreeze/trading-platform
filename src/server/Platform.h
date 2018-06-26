#include "Bid.h"
#include "Ask.h"
#include <vector>

class Platform {
public:
Platform();
void addBid(int sender, Bid b);
void addAsk(int sender, Ask a);
void printAll();
void clear();
private:
std::vector<Bid> bids;
std::vector<Ask> asks;
};
