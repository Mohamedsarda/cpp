#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string target;
public:
    std::string const &getTarget() const;
    void execute(Bureaucrat const & executor) const;
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm(std::string _name);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
};

#endif // SHRUBBERY_CREATION_FORM_HPP
