#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
    
}

AMateria::AMateria() : _type("AMateria") {

}

std::string const & AMateria::getType() const {
    return _type;
}

AMateria::~AMateria() {
    
}