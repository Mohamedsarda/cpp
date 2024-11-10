#include "Form.hpp"

const char *Form::GradeTooLowException::what() const throw() {
    return "Form Grade Too Low";
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form Grade Too High";
}

//

std::string const & Form::getName() const {
    return (name);
}

bool Form::getIsSigned() const {
    return (isSigned);
}

const int & Form::getSignIt() const {
    return (sign_it);
}

const int & Form::getExecuteIt() const {
    return (execute_it);
}


//

// Form &Form::operator=(const Form &copy) {
//     return *this;
// }

Form::Form(const std::string &_name, const int &_sign_it, const int &_execute_it) :
    name(_name), sign_it(_sign_it), execute_it(_execute_it)
{
    isSigned = false;
    if (execute_it < 1 || sign_it < 1)
        throw GradeTooHighException();
    if (execute_it > 150 || sign_it > 150)
        throw GradeTooLowException();
}

// Form::Form(const Form &copy) {
//     isSigned = false;

// }

Form::Form() : name("Form"), sign_it(0), execute_it(0) {
    isSigned = false;
}

Form::~Form() {

}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
    out << "Name : " << obj.getName() << std::endl;
    out << "Is Signed : " << obj.getIsSigned() << std::endl;
    out << "Sign It : " << obj.getSignIt() << std::endl;
    out << "Execute It : " << obj.getExecuteIt();
    return out;
}
