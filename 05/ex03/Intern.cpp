#include "Intern.hpp"

Intern &Intern::operator=(const Intern &copy) {
    (void)copy;
    return *this;
}

Intern::Intern() {

}

Intern::Intern(const Intern &copy) {
    (void)copy;
}

Intern::~Intern() {

}

const char *Intern::FormNotFound::what() const throw(){
    return ("Form Not Found");
}

AForm *Intern::makeForm(std::string type, std::string target) {
    AForm *tmp = NULL;
    if (type == "RobotomyRequestForm")
        tmp = new RobotomyRequestForm(target);
    else if (type == "PresidentialPardonForm")
        tmp = new PresidentialPardonForm(target);
    else if (type == "ShrubberyCreationForm")
        tmp = new ShrubberyCreationForm(target);
    else
        throw FormNotFound();
    std::cout << "Intern creates " << type << std::endl;
    return tmp;
}
