#include "PresidentialPardonForm.hpp"

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw SignIsFalse();
    if (executor.getGrade() < getExecuteIt())
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
        throw GradeTooLowException();
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    if (this != &copy)
    {
        setIsSigned(copy.getIsSigned());
        target = copy.target;
    }
    return *this;
}

//
PresidentialPardonForm::PresidentialPardonForm(std::string _name)
    : AForm("PresidentialPardonForm", 25, 5)
{
    target = _name;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    :AForm("PresidentialPardonForm", copy.getSignIt(), copy.getExecuteIt())
{
    setIsSigned(copy.getIsSigned());
    target = copy.target;
}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5)
{
    target = "target";
}

PresidentialPardonForm::~PresidentialPardonForm() {

}
