#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int main() {
    std::string s[] = {"     .-.    ",
                       "    (   ).  ",
                       "   ((    ) ",
                       "   /' \\* / * ",
                       "  *\\ '/  \\'"};
    std::cout << s[0] << '\n'
              << s[1] << '\n'
              << s[2] << '\n'
              << s[3] << '\n'
              << s[4] << '\n';
    system("pause");
    return 0;
}
