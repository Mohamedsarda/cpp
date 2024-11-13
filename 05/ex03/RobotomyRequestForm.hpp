#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        std::string const &getTarget() const;
        void execute(Bureaucrat const & executor) const;
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        RobotomyRequestForm(std::string _name);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm();
        ~RobotomyRequestForm();
};

#endif
