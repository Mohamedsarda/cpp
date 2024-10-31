#include "Cure.hpp"

Cure* Cure::clone() const {
    Cure *clone = new Cure(this->_type);
    return (clone);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals "<< getType() << "’s wounds *" << std::endl;
}

Cure::Cure(std::string const type) {
    this->_type = type;
}

Cure::Cure(const Cure &copy) {
    this->_type = copy.getType();
}

//
Cure &Cure::operator=(const Cure &copy) {
    if (this != &copy)
        this->_type = copy.getType();
    return (*this);
}


Cure::Cure() : AMateria("cure"){

}

Cure::~Cure()
{

}