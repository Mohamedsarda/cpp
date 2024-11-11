#include "ShrubberyCreationForm.hpp"

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) {

}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy)
        target = copy.target;
    return *this;
}

//
ShrubberyCreationForm::ShrubberyCreationForm(std::string _name)
    : AForm("ShrubberyCreationForm", 145, 137)
{
    target = _name;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    :AForm("ShrubberyCreationForm", copy.getSignIt(), copy.getExecuteIt())
{
    target = copy.target;
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 150, 150)
{
    target = "target";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

int main()
{
    ShrubberyCreationForm p1;
    Bureaucrat p2;
}
