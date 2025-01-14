#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Form form("sarda", 120, 45);
        Bureaucrat bur1("med", 120);
        form.beSigned(bur1);
        std::cout << form << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        bur1.signForm(form);
    } catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
