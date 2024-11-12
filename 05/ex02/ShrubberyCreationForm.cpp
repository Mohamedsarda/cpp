#include "ShrubberyCreationForm.hpp"

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() >= getExecuteIt() && getIsSigned() == true)
    {
        std::string file = getName() + "_shrubbery";
        std::ofstream out(file);
        if (!out.is_open())
        {
            std::cout << "Couldn't create the file : " << file << std::endl;
        }
        out << "        &&&        " << std::endl;
        out << "       &&&&&       " << std::endl;
        out << "      &&&&&&&      " << std::endl;
        out << "     &&&&&&&&&     " << std::endl;
        out << "    &&&&&&&&&&&    " << std::endl;
        out << "   &&&&&&&&&&&&&   " << std::endl;
        out << "  &&&&&&&&&&&&&&&  " << std::endl;
        out << "   &&&&&&&&&&&&&   " << std::endl;
        out << "    &&&&&&&&&&&    " << std::endl;
        out << "     &&&&&&&&&     " << std::endl;
        out << "        |||        " << std::endl;
        out << "        |||        " << std::endl;
        out << "        |||        " << std::endl;
        std::cout << "The ASCII trees is inside : " << file << std::endl;
    }
    else
        throw GradeTooLowException();
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy)
    {
        target = copy.target;
        setIsSigned(copy.getIsSigned());
    }
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
    setIsSigned(copy.getIsSigned());
    target = copy.target;
}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137)
{
    target = "target";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}
