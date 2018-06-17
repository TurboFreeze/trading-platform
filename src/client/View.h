#include <string>
#include <vector>

class View {
public:
View();
void welcome();
void error(std::string message);
std::string get_input();
double get_input_double(std::string prompt);
int get_input_int(std::string prompt);
int get_option(std::string prompt, std::vector<int> options);
};
