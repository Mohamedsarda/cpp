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
    PhoneBook   book;
    
    while (1)
    {
        std::cout << "Enter A Command   :  ";
        if (!std::getline(std::cin, input))
            return (1);
        if (input == "ADD")
            book.ft_add_to_book(&book);
        else if (input == "SEARCH")
            book.ft_showTable(book);
        else if (input == "EXIT")
        {
            std::cout << "Exit" << std::endl;
            std::exit(0);
        }
        else
            continue ;
    }
}
