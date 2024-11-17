#include "RobotomyRequestForm.hpp"

std::string const &RobotomyRequestForm::getTarget() const {
    return target;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw SignIsFalse();
    if (executor.getGrade() < getExecuteIt())
    {
        std::cout << "Making some drilling noises..." << std::endl;
        std::srand((unsigned int)(std::time(0)));
        if (std::rand() % 2 == 0)
            std::cout << target << " has been robotomized successfully!" << std::endl;
        else
            std::cout << target << " the robotomy failed." << std::endl;
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
    : AForm("RobotomyRequestForm", 72, 45)
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
    : AForm("RobotomyRequestForm", 72, 45)
{
    target = "target";
}

RobotomyRequestForm::~RobotomyRequestForm() {

}
