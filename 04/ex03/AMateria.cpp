#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
    
}

AMateria &AMateria::operator=(const AMateria &copy) {
    if (this != &copy)
        this->_type = copy.getType();
    return *this;
}

AMateria::AMateria(const AMateria &copy) {
    this->_type = copy.getType();
}

AMateria::AMateria(std::string const & type) {
    this->_type = type;
}


AMateria::AMateria() : _type("AMateria") {

}

std::string const & AMateria::getType() const {
    return _type;
}

AMateria::~AMateria() {
    
}