#include "Animal.hpp"

std::string    Animal::getType() const
{
    return (type);
}

void           Animal::setType(std::string _type)
{
    type = _type;
}
//
void   Animal::makeSound( void ) const
{
    std::cout << "Animal Sound ..." << std::endl;
}
//
Animal::Animal(const Animal &copy)
{
    setType(copy.getType());
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        setType(copy.getType());
    std::cout << "Animal Copy Assignment Operator Called" << std::endl;
    return (*this);
}

//
Animal::Animal()
{
    setType("Animal");
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(std::string _type)
{
    setType(_type);
    std::cout << "Animal Constructor Called For " << getType() << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called For " << getType() << std::endl;
}
