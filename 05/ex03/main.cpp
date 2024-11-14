#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Intern intern;
        //ShrubberyCreationForm - PresidentialPardonForm - RobotomyRequestForm
        AForm *form1 = intern.makeForm("ShrubberyCreationForm", "med");
        AForm *form2 = intern.makeForm("PresidentialPardonForm", "sarda");
        AForm *form3 = intern.makeForm("RobotomyRequestForm", "msarda");
        delete form1;
        delete form2;
        delete form3;
        AForm *form4 = intern.makeForm("RobotomyRequestFor", "msarda");
        delete form4;
        form4->getName();
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
