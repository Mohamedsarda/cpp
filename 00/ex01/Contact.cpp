#include "Contact.hpp"

// first_name

std::string Contact::get_first_name()
{
    return (FristName);
}

void    Contact::set_FristName(std::string FristName)
{
    this->FristName = FristName;
}

// last_name

std::string Contact::get_last_name()
{
    return (LastName);
}

void    Contact::set_LastName(std::string LastName)
{
    this->LastName = LastName;
}

// nick_name

std::string Contact::get_nick_name()
{
    return (NickName);
}

void    Contact::set_nick_name(std::string NickName)
{
    this->NickName = NickName;
}

// phone_number

std::string Contact::get_phone_number()
{
    return (Phone);
}

void    Contact::set_phone_number(std::string Phone)
{
    this->Phone = Phone;
}

// darkest_secret

std::string Contact::get_darkest_secret()
{
    return (DarkestSecret);
}

void    Contact::set_darkest_secret(std::string DarkestSecret)
{
    this->DarkestSecret = DarkestSecret;
}
