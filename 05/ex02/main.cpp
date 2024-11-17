#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try {
        ShrubberyCreationForm form1;
        PresidentialPardonForm form2;
        RobotomyRequestForm form3;
        Bureaucrat bureaucrat("Bureaucrat", 4);
        // std::cout << form1 << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        std::cout << "\t\t---------" << std::endl;
        // std::cout << form2 << std::endl;
        form3.beSigned(bureaucrat);
        form3.execute(bureaucrat);
        std::cout << "\t\t---------" << std::endl;
        // std::cout << form3 << std::endl;
        bureaucrat.signForm(form2);
        form2.execute(bureaucrat);
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
