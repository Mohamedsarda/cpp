#include "../PhoneBook.hpp"

Contact    PhoneBook::ft_get_contact(int i)
{
    Contact contact;

    contact.set_LastName(Contacts[i].get_last_name());
    contact.set_nick_name(Contacts[i].get_nick_name());
    contact.set_FristName(Contacts[i].get_first_name());
    contact.set_phone_number(Contacts[i].get_phone_number());
    contact.set_darkest_secret(Contacts[i].get_darkest_secret());
    return (contact);
}


void    PhoneBook::ft_print_contact(Contact contact, int i)
{
    std::cout << "#    "<< i + 1 << "    |";
    print_line(contact.get_first_name());
    std::cout << "|";
    print_line(contact.get_last_name());
    std::cout << "|";
    print_line(contact.get_nick_name());
    std::cout << "#" << std::endl;
}

void    PhoneBook::ft_showTable(PhoneBook book)
{
    std::string input;
    Contact     contact;
    int         i = -1;

    std::cout << "############################################" << std::endl;
    std::cout << "#  Index  #  F Name  #  L Name  #  N Name  #" << std::endl;
    while (++i < 8)
    {
        if (book.ft_get_contact(0).get_first_name().empty())
        {
            std::cout << "#               No Data Found              #" << std::endl;
            std::cout << "############################################" << std::endl;
            return ;
        }
        ft_print_contact(book.ft_get_contact(i), i);
    }
    std::cout << "############################################" << std::endl;
    while (1)
    {
        std::cout << "Search With Index : ";
        if (!std::getline(std::cin, input))
            exit (0);
        if (!input.empty() && input.length() == 1 && input[0] >= '1' && input[0] <= '8')
        {
            contact = ft_get_contact(std::stoi(input) - 1);
            if (contact.get_first_name().empty())
                return ;
            std::cout << "Id               : " << input << std::endl;
            std::cout << "First Name       : " << contact.get_first_name() << std::endl;
            std::cout << "Last Name        : " << contact.get_last_name() << std::endl;
            std::cout << "Nick Name        : " << contact.get_nick_name() << std::endl;
            std::cout << "Phone Number     : " << contact.get_phone_number() << std::endl;
            std::cout << "Darkest Sercret  : " << contact.get_darkest_secret() << std::endl;
            return ;
        }
        else
            std::cout << "\033[31mPlease Enter An Index From 1 - 8\033[0m" << std::endl;
    }
}
