#include "PhoneBook.hpp"

void    PhoneBook::ft_add_to_book(PhoneBook *book)
{
    (void)book;
    std::string input;
    Contact     NewContact;
    // static int  NumContact;

    while (1)
    {
        std::cout << "Enter You First Name\n";
        if (!std::getline(std::cin, input))
            exit(1);
        if (input.empty())
            std::cout << "The Input Is Empty Try Again\n";
        else
            break ;
    }
    NewContact.set_FristName(input);
}