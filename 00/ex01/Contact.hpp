#ifndef CONTACT_HPP
#define CONTACT_HPP

# include "iostream"

class Contact
{
    private:
        std::string FristName;
        std::string LastName;
        std::string NickName;
        std::string Phone;
        std::string DarkestSecret;
    public:
        // get
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nick_name();
        std::string get_phone_number();
        std::string get_darkest_secret();
        // set
        void    set_FristName(std::string FristName);
        void    set_LastName(std::string LastName);
        void    set_nick_name(std::string NickName);
        void    set_phone_number(std::string Phone);
        void    set_darkest_secret(std::string DarkestSecret);
        //
        Contact();
        ~Contact();
};

#endif