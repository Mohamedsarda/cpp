#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat Grade Too Low");
}

std::string const Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

//
void Bureaucrat::increment() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrement() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    else
        grade++;
}

//
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        grade = copy.getGrade();
    return *this;
}

//
Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name), grade(_grade) {
    // std::cout << "" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name) {
    if (this != &copy)
        grade = copy.getGrade();
}

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(1) {
    // std::cout << "" << std::endl;
}

Bureaucrat::~Bureaucrat() {

}

void Bureaucrat::signForm(Form &obj) {
    try {
        obj.beSigned(*this);
        std::cout << *this << " signed " << std::endl << obj << std::endl;
    } catch (const std::exception &e)
    {
        std::cerr << *this << " couldn’t sign ";
        std::cerr << obj << " because ";
        std::cerr << e.what() << std::endl;
    }
}

//<name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}
