#include "Cat.hpp"

void   Cat::makeSound( void ) const
{
    std::cout << "Cat meows meoooow ..." << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        setType(copy.getType());
    std::cout << "Cat Copy Assignment Operator Called" << std::endl;
    return (*this);
}
        //
Cat::Cat(std::string _type)
{
    setType(_type);
    std::cout << "Cat Constructor Called For " << getType() << std::endl;
}

Cat::Cat(const Cat &copy)
{
    setType(copy.getType());
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat::Cat()
{
    setType("Cat");
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called For " << getType() << std::endl;
}
