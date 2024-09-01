#include "PhoneBook.hpp"

int PhoneBook::ft_parse_name(std::string name)
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

int PhoneBook::ft_check_name(std::string input, int isName)
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