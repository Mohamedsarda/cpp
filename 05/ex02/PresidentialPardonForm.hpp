#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        void execute(Bureaucrat const & executor) const;
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        PresidentialPardonForm(std::string _name);
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm();
        ~PresidentialPardonForm();
};

#endif
