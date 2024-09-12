#include "../PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::ft_insert_to_book(PhoneBook *book, Contact New, int *i)
{
    if ((*i) > 7)
        (*i) = 0;
    book->Contacts[(*i)].set_FristName(New.get_first_name());
    book->Contacts[(*i)].set_LastName(New.get_last_name());
    book->Contacts[(*i)].set_phone_number(New.get_phone_number());
    book->Contacts[(*i)].set_nick_name(New.get_nick_name());
    book->Contacts[(*i)].set_darkest_secret(New.get_darkest_secret());
    (*i)++;
}

void    PhoneBook::ft_add_to_book(PhoneBook *book)
{
    (void)book;
    std::string input;
    Contact     NewContact;
    int         isName = 1;
    unsigned long   i = 0;
    static int  NumContact;

    while (1)
    {
        std::cout << "Enter Your First Name : ";
        if (!std::getline(std::cin, input))
            exit(0);
        if (input.empty())
            std::cout << "\033[31mThe Input Is Empty Try Again\033[0m\n";
        if (ft_check_name(input, isName) == 1)
            break ;
    }
    NewContact.set_FristName(input);
    while (1)
    {
        std::cout << "Enter Your Last Name : ";
        if (!std::getline(std::cin, input))
            exit(0);
        if (input.empty())
            std::cout << "\033[31mThe Input Is Empty Try Again\033[0m\n";
        if (ft_check_name(input, isName) == 1)
            break ;
    }
    NewContact.set_LastName(input);
    while (1)
    {
        std::cout << "Enter Your Phone Number : ";
        if (!std::getline(std::cin, input))
            exit(0);
        if (input.empty() || input.length() != 10)
        {
            std::cout << "\033[31mThe Phone Number You Provided Is Wrong\033[0m\n";
            continue ;
        }
        int isValid = 1;
        while (i < input.length())
        {
            if (!isdigit(input[i]))
            {
                std::cout << "\033[31mThe Phone Number Should be a Number with 10 digits\033[0m\n";
                isValid = 0;
                break ;
            }
            i++;
        }
        if (isValid)
            break ;
    }
    NewContact.set_phone_number(input);
    while (1)
    {
        std::cout << "Enter Your Nick Name : ";
        if (!std::getline(std::cin, input))
            exit(0);
        if (input.empty())
            std::cout << "\033[31mThe Input Is Empty Try Again\033[0m\n";
        if (ft_check_name(input, isName) == 1)
            break ;
    }
    NewContact.set_nick_name(input);
    while (1)
    {
        std::cout << "Enter Your Darkest Secret : ";
        if (!std::getline(std::cin, input))
            exit(0);
        if (input.empty())
            std::cout << "\033[31mThe Input Is Empty Try Again\033[0m\n";
        else
            break ;
    }
    NewContact.set_darkest_secret(input);
    book->ft_insert_to_book(book, NewContact, &NumContact);
}

