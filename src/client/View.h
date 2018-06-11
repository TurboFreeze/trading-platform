#include <string>
#include <vector>

class View {
public:
View();
void welcome();
void error(std::string message);
std::string get_input();
double get_input(std::string prompt);
int get_input(std::string prompt, std::vector<int> options);
};
