#include "ScalarConverter.hpp"


int main(int c, char **ar)
{
    if (c != 2)
        return 1;
    (void)ar;
    // std::cout << isChar("/") << std::endl;
    // std::cout << isInt(" 798465") << std::endl;
    std::cout << isFloat("-1.24ff") << std::endl;
    std::cout << isDouble(".0") << std::endl;
}
