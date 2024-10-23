#include "Dog.hpp"

void   Dog::makeSound( void ) const
{
    std::cout << "Dog barks woof woof ..." << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        setType(copy.getType());
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Dog Copy Assignment Operator Called" << std::endl;
    return (*this);
}
        //
Dog::Dog(std::string _type)
{
    setType(_type);
    this->brain = new Brain();
    std::cout << "Dog Constructor Called For " << getType() << std::endl;
}

Dog::Dog(const Dog &copy)
{
    setType(copy.getType());
    if (brain)
        delete brain;
    brain = new Brain(*copy.brain);
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog::Dog()
{
    setType("Dog");
    brain = new Brain();
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor Called For " << getType() << std::endl;
}
