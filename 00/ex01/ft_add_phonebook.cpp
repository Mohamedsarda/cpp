#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

int ft_parse_name(std::string name)
{
    unsigned long i = 0;
    unsigned long j = 0;

    if (name.length() < 3 || name.length() > 15)
        return (-1);
    while (i < name.length())
    {
        if (isdigit(name[i]))
            return (0);
        if (isalpha(name[j]))
            j++;
        i++;
    }
    if (j == name.length())
        return (1);
    return (0);
}

int ft_check_name(std::string input, int isName)
{
    isName = ft_parse_name(input);
    if (isName == 1)
        return (1);
    else if (isName == 0)
        std::cout << "\033[31mThe First And Last And Nick Name Should Not Contain A Digit\033[0m\n";
    else if (isName == -1)
        std::cout << "\033[31mThe First And Last And Nick Name Should At Least Have 3 Characters And Less Then 15\033[0m\n";
    return (0);
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
            exit(1);
        if (input.empty())
            std::cout << "The Input Is Empty Try Again\n";
        if (ft_check_name(input, isName) == 1)
            break ;
    }
    NewContact.set_FristName(input);
    while (1)
    {
        std::cout << "Enter Your Last Name : ";
        if (!std::getline(std::cin, input))
            exit(1);
        if (input.empty())
            std::cout << "The Input Is Empty Try Again\n";
        if (ft_check_name(input, isName) == 1)
            break ;
    }
    NewContact.set_LastName(input);
    while (1)
    {
        std::cout << "Enter Your Phone Number : ";
        if (!std::getline(std::cin, input))
            exit(1);
        if (input.empty() || input.length() != 10)
        {
            std::cout << "The Phone Number You Provided Is Wrong\n";
            continue ;
        }
        int isValid = 1;
        while (i < input.length())
        {
            if (!isdigit(input[i]))
            {
                std::cout << "The Phone Number Should be a Number with 10 digits\n";
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
            exit(1);
        if (input.empty())
            std::cout << "The Input Is Empty Try Again\n";
        if (ft_check_name(input, isName) == 1)
            break ;
    }
    NewContact.set_nick_name(input);
    while (1)
    {
        std::cout << "Enter Your Darkest Secret : ";
        if (!std::getline(std::cin, input))
            exit(1);
        if (input.empty())
            std::cout << "The Input Is Empty Try Again\n";
        else
            break ;
    }
    NewContact.set_darkest_secret(input);
    book->ft_insert_to_book(book, NewContact, &NumContact);
}