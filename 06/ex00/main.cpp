#include "ScalarConverter.hpp"


int main(int c, char **ar)
{
    if (c != 2)
        return 1;
    try {
        ScalarConverter::convert(ar[1]);
    } catch (char const *str)
    {
        std::cerr << str << std::endl;
    }
}
