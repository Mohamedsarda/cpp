#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this->_type = type;
}

AMateria &AMateria::operator=(const AMateria &copy) {
    if (this != &copy)
        this->_type = copy.getType();
    return *this;
}

AMateria::AMateria(const AMateria &copy) {
    *this = copy;
}

AMateria::AMateria(std::string const & type) {
    this->_type = type;
}


AMateria::AMateria() {
    this->_type = "AMateria";
}

std::string const & AMateria::getType() const {
    return _type;
}

AMateria::~AMateria() {
    
}

void AMateria::use(ICharacter& target) {
    (void)target;
}