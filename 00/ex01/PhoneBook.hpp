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
        PhoneBook();
        ~PhoneBook();
};

#endif