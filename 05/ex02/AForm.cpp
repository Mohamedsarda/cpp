#include "AForm.hpp"

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm Grade Too Low";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm Grade Too High";
}

//

std::string const & AForm::getName() const {
    return (name);
}

bool AForm::getIsSigned() const {
    return (isSigned);
}

const int & AForm::getSignIt() const {
    return (sign_it);
}

const int & AForm::getExecuteIt() const {
    return (execute_it);
}


//

AForm &AForm::operator=(const AForm &copy) {
    if (this != &copy)
        isSigned = false;
    return *this;
}

AForm::AForm(const std::string &_name, const int &_sign_it, const int &_execute_it) :
    name(_name), sign_it(_sign_it), execute_it(_execute_it)
{
    isSigned = false;
    if (execute_it < 1 || sign_it < 1)
        throw GradeTooHighException();
    if (execute_it > 150 || sign_it > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
: name(copy.getName()), sign_it(copy.getSignIt()), execute_it(copy.getExecuteIt())  {
    if (this != &copy)
        isSigned = false;
}

AForm::AForm() : name("AForm"), sign_it(0), execute_it(0) {
    isSigned = false;
}

AForm::~AForm() {

}

void    AForm::beSigned(Bureaucrat &obj) {
    if (obj.getGrade() <= sign_it)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
    out << "Name : " << obj.getName() << std::endl;
    out << "Is Signed : " << obj.getIsSigned() << std::endl;
    out << "Sign It : " << obj.getSignIt() << std::endl;
    out << "Execute It : " << obj.getExecuteIt();
    return out;
}
