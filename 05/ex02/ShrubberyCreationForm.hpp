#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
public:
    void execute(Bureaucrat const & executor);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm(std::string _name);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
};

#endif // SHRUBBERY_CREATION_FORM_HPP
