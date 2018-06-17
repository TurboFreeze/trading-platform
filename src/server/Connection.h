class Connection {
public:
Connection(int connection);
void get_bid();
double read_stream_double();
int read_stream_int();
void option_handle(int option);
void start();
private:
int socket;
};
