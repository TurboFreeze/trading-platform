#include "View.h"

class Controller {
public:
Controller(int connection);
void submit_bid();
void start();
private:
int socket;
View v;
};
