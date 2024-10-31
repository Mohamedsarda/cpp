#include "Ice.hpp"

Ice* Ice::clone() const {
    Ice *tmp = new Ice(this->_type);
    return (tmp);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << getType() << "*" << std::endl;
}

//
Ice &Ice::operator=(const Ice &copy) {
    if (this != &copy)
        this->_type = copy.getType();
    return (*this);
}

//
Ice::Ice(const Ice &copy) {
    this->_type = copy.getType();
}

Ice::Ice(std::string const type) {
    this->_type = type;
}


Ice::Ice() : AMateria("ice") {

}

Ice::~Ice() {

}
