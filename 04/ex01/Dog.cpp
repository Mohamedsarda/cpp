#include "Dog.hpp"

void   Dog::makeSound( void ) const
{
    std::cout << "Dog barks woof woof ..." << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
        setType(copy.getType());
    std::cout << "Dog Copy Assignment Operator Called" << std::endl;
    return (*this);
}
        //
Dog::Dog(std::string _type)
{
    setType(_type);
    std::cout << "Dog Constructor Called For " << getType() << std::endl;
}

Dog::Dog(const Dog &copy)
{
    setType(copy.getType());
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog::Dog()
{
    setType("Dog");
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called For " << getType() << std::endl;
}
