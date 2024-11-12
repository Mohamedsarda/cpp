#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        AForm *form1 = new ShrubberyCreationForm;
        AForm *form2 = new PresidentialPardonForm;
        Bureaucrat bureaucrat("Bureaucrat", 146);
        std::cout << *form1 << std::endl;
        form1->beSigned(bureaucrat);
        form1->execute(bureaucrat);
        std::cout << "-" << std::endl;
        std::cout << *form2 << std::endl;
        form2->beSigned(bureaucrat);
        form2->execute(bureaucrat);
        std::cout << "-" << std::endl;
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
