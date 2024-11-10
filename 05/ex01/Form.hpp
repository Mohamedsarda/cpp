#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

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
        std::string const & getName() const;
        bool getIsSigned() const;
        const int & getSignIt() const;
        const int & getExecuteIt() const;
        //
        void    beSigned(Bureaucrat &obj);
        //
        Form &operator=(const Form &copy);
        Form(const std::string &_name, const int &_sign_it, const int &_execute_it);
        Form(const Form &copy);
        Form();
        ~Form();
};


std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif
