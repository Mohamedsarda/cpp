#include "Cat.hpp"

void   Cat::makeSound( void ) const
{
    std::cout << "Cat meows meoooow ..." << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        setType(copy.getType());
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    std::cout << "Cat Copy Assignment Operator Called" << std::endl;
    return (*this);
}
        //
Cat::Cat(std::string _type)
{
    setType(_type);
    brain = new Brain();
    std::cout << "Cat Constructor Called For " << getType() << std::endl;
}

Cat::Cat(const Cat &copy)
{
    setType(copy.getType());
    this->brain = new Brain(*copy.brain);
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat::Cat()
{
    setType("Cat");
    brain = new Brain();
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat Destructor Called For " << getType() << std::endl;
}
