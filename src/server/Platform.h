#include "Bid.h"
#include <vector>

class Platform {
public:
Platform();
void run();
private:
std::vector<Bid> bids;
};
