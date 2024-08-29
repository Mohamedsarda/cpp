#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

int main(int c, char **ar)
{
    (void)ar;
    if (c != 1)
    {
        std::cout << "Too many arguments !" << std::endl;
        return (1);
    }
    std::string input;
    PhoneBook book;
    while (1)
    {
        std::cout << "-> : ";
        if (!std::getline(std::cin, input))
            return (1);
        std::cout << input << std::endl;
        if (input == "ADD")
        {
            std::cout << "do add shit" << std::endl;
        }
        else if (input == "SEARCH")
            std::cout << "do search shit" << std::endl;
        else if (input == "EXIT")
        {
            std::cout << "By till next time" << std::endl;
            exit(0);
        }
        else
            continue ;
    }
}