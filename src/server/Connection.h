#include "Platform.h"

class Connection {
public:
Connection(int connection, Platform* p);
void get_bid();
void get_ask();
double read_stream_double();
int read_stream_int();
void option_handle(int option);
void start();
private:
Platform* parent;
int socket;
};
