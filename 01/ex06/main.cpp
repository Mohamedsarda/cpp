#include "Harl.hpp"

int main(int c, char **arg)
{
    if (c != 2)
    {
        std::cout << "Enter 2 parameters to use the program" << std::endl;
        return (1);
    }

    Harl harl;

    harl.complain(arg[1]);
    return (0);
}