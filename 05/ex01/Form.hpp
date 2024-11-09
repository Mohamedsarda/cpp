#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int sign_it;
        const int execute_it;
    public:
        //
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        //
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        //
        Form &operator=(const Form &copy);
        Form(const std::string &name, const int &_sign_it, const int &_execute_it);
        Form(const Form &copy);
        Form();
        ~Form();
};


#endif