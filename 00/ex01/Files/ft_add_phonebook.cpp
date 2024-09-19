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

std::string    ft_insert_data(std::string name, int type)
{
    unsigned long i = 0;
    std::string   input;

    switch (type)
    {
        case 1:
            while (1)
            {
                std::cout << "Enter Your " << name << " : ";
                if (!std::getline(std::cin, input))
                    exit(0);
                if (input.empty())
                {
                    std::cout << "\033[31mThe Input Is Empty Try Again\033[0m" << std::endl;
                    continue ;
                }
                if (ft_check_name(input) == 1)
                    break ;
            }
            break;
        case 2:
                while (1)
                {
                    std::cout << "Enter Your " << name << " : ";
                    if (!std::getline(std::cin, input))
                        exit(0);
                    if (input.empty())
                    {
                        std::cout << "\033[31mThe Input Is Empty Try Again\033[0m" << std::endl;
                        continue ;
                    }
                    if (name == "Darkest Secret")
                        break ;
                    if (ft_check_name(input) == 1)
                        break ;
                }
                break ;
        case 3:
            while (1)
            {
                i = 0;
                std::cout << "Enter Your " << name << " : ";
                if (!std::getline(std::cin, input))
                    exit(0);
                if (input.empty() || input.length() != 10)
                {
                    std::cout << "\033[31mThe Phone Number You Provided Is Wrong\033[0m" << std::endl;
                    continue ;
                }
                int isValid = 1;
                while (i < input.length())
                {
                    if (!std::isdigit(input[i]))
                    {
                        std::cout << "\033[31mThe Phone Number Should be a Number with 10 digits\033[0m" << std::endl;
                        isValid = 0;
                        break ;
                    }
                    i++;
                }
                if (isValid)
                    break ;
            }
            break ;
    }
    return (input);
}

void    PhoneBook::ft_add_to_book(PhoneBook *book)
{
    (void)book;
    std::string input;
    Contact     NewContact;
    static int  NumContact;


    input = ft_insert_data("First Name", 1);
    NewContact.set_FristName(input);

    input = ft_insert_data("Last Name", 1);
    NewContact.set_LastName(input);

    input = ft_insert_data("Phone Number", 3);
    NewContact.set_phone_number(input);

    input = ft_insert_data("Nick Name", 2);
    NewContact.set_nick_name(input);

    input = ft_insert_data("Darkest Secret", 2);
    NewContact.set_darkest_secret(input);
    book->ft_insert_to_book(book, NewContact, &NumContact);
}
