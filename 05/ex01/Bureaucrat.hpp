#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
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
        std::string const getName() const;
        int getGrade() const;
        //
        void increment();
        void decrement();
        //
        void signForm(Form &obj);
        //
        Bureaucrat &operator=(const Bureaucrat &copy);
        //
        Bureaucrat(std::string const _name, int _grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat();
        ~Bureaucrat();
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
