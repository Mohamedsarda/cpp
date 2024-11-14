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
    std::string forms[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
    int i = ((forms[0] == type) * 1) + ((forms[1] == type) * 2) + ((forms[2] == type) * 3);
    switch (i)
    {
        case 1:
            tmp = new RobotomyRequestForm(target);
            break;
        case 2:
            tmp = new PresidentialPardonForm(target);
            break;
        case 3:
            tmp = new ShrubberyCreationForm(target);
            break;
        default :
            throw FormNotFound();
    }
    std::cout << "Intern creates " << type << std::endl;
    return tmp;
}
