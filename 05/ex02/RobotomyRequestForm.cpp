#include "RobotomyRequestForm.hpp"

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw SignIsFalse();
    if (executor.getGrade() >= getSignIt())
    {

    }
    else
        throw GradeTooLowException();
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy)
    {
        setIsSigned(copy.getIsSigned());
        target = copy.target;
    }
    return *this;
}

//
RobotomyRequestForm::RobotomyRequestForm(std::string _name)
    : AForm("RobotomyRequestForm", 25, 5)
{
    target = _name;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    :AForm("RobotomyRequestForm", copy.getSignIt(), copy.getExecuteIt())
{
    setIsSigned(copy.getIsSigned());
    target = copy.target;
}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 25, 5)
{
    target = "target";
}

RobotomyRequestForm::~RobotomyRequestForm() {

}
