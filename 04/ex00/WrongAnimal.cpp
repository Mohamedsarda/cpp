#include "WrongAnimal.hpp"

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::setType(std::string _type)
{
    type = _type;
}

//
void WrongAnimal::makeSound( void ) const
{
    std::cout << "Wrong Animal sound" << std::endl;
}

//
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        setType(copy.getType());
    std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
    return (*this);
}

//
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    setType(copy.getType());
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type)
{
    setType(_type);
    std::cout << "WrongAnimal Constructor Called For " << getType() << std::endl;
}

//
WrongAnimal::WrongAnimal()
{
    setType("WrongAnimal");
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called For " << getType() << std::endl;
}