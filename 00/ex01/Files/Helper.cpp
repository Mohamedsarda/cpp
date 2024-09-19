#include "../PhoneBook.hpp"

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
        if (isalpha(name[j]) || name[j] == ' ')
            j++;
        i++;
    }
    if (j == name.length())
        return (1);
    return (0);
}

int ft_check_name(std::string input)
{
    int isName = ft_parse_name(input);
    
    if (isName == 1)
        return (1);
    else if (isName == 0)
        std::cout << "\033[31mThe First And Last And Nick Name Should Not Contain A Digit\033[0m" << std::endl;
    else if (isName == -1)
        std::cout << "\033[31mThe First And Last And Nick Name Should At Least Have 3 Characters And Less Then 15\033[0m" << std::endl;
    return (0);
}

void    print_line(std::string input)
{
    int         i = 0;

    if (input.length() > 10)
		input[9] = '.';
	else if (input.length() < 10 && !input.empty())
	{
		i = input.length();
		while (i++ < 10)
			std::cout << " ";
	}
	if (input.length() > 10 || input.empty())
		input.resize(10, ' ');
	std::cout << input;
}
