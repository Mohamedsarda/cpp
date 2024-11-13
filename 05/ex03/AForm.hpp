#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
        class SignIsFalse : public std::exception
        {
            public:
                const char *what() const throw();
        };
        //
        std::string const & getName() const;
        bool getIsSigned() const;
        void setIsSigned(bool _is_signed);
        const int & getSignIt() const;
        const int & getExecuteIt() const;
        //
        virtual std::string const &getTarget() const = 0;
        virtual void execute(Bureaucrat const & executor) const = 0;
        //
        void    beSigned(Bureaucrat &obj);
        //
        AForm &operator=(const AForm &copy);
        AForm(const std::string &_name, const int &_sign_it, const int &_execute_it);
        AForm(const AForm &copy);
        AForm();
        virtual ~AForm();
};


std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif
