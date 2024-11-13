#ifndef INTERN_HPP
#define INTERN_HPP

#include "iostream"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        class FormNotFound : public std::exception {
            public:
                const char *what() const throw();
        };
        //
        AForm *makeForm(std::string type, std::string target);
        //
        Intern &operator=(const Intern &copy);
        Intern();
        Intern(const Intern &copy);
        ~Intern();
};

#endif