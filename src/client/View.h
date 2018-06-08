#include <string>
#include <vector>

class View {
public:
View();
void welcome();
std::string get_input();
int get_input(std::string prompt, std::vector<int> options);
};
