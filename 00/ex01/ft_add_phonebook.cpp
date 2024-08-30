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
        std::cout << "The First And Last Name Should Not Contain A Digit\n";
    else if (isName == -1)
        std::cout << "The First And Last Name Should At Least Have 3 Characters And Less Then 15\n";
    return (0);
}

void    PhoneBook::ft_add_to_book(PhoneBook *book)
{
    (void)book;
    std::string input;
    Contact     NewContact;
    int         isName;
    unsigned long   i = 0;
    // static int  NumContact;

    while (1)
    {
        std::cout << "Enter You First Name : ";
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
        std::cout << "Enter You Last Name : ";
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
        std::cout << "Enter You Phone Number : ";
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
}