#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <sstream>

class PhoneBook
{
    private:
        Contact Contacts[8];
    public:
        void    ft_add_to_book(PhoneBook *book);
        //
        void    ft_insert_to_book(PhoneBook *book, Contact New, int *i);
        void    ft_print_contact(Contact contact, int i);
        void    ft_showTable(PhoneBook book);
        Contact ft_get_contact(int i);
        PhoneBook();
        ~PhoneBook();
};

#endif