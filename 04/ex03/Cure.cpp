#include "Cure.hpp"

Cure* Cure::clone() const {
    Cure *clone = new Cure(*this);
    return (clone);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals "<< getType() << "’s wounds *" << std::endl;
}

Cure::Cure(std::string const type) {
    this->_type = type;
}

Cure::Cure(const Cure &copy) {
    *this = copy;
}

//
Cure &Cure::operator=(const Cure &copy) {
    if (this != &copy)
        this->_type = copy.getType();
    return (*this);
}


Cure::Cure() {
    this->_type = "cure";
}

Cure::~Cure()
{

}