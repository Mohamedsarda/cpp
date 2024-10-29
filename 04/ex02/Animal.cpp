#include "Animal.hpp"

std::string    Animal::getType() const
{
    return (type);
}

void           Animal::setType(std::string _type)
{
    type = _type;
}

// Animal::Animal(const Animal &copy)
// {
//     setType(copy.getType());
//     std::cout << "Animal Copy Constructor Called" << std::endl;
// }

// Animal &Animal::operator=(const Animal &copy)
// {
//     if (this != &copy)
//         setType(copy.getType());
//     std::cout << "Animal Copy Assignment Operator Called" << std::endl;
//     return (*this);
// }


Animal::~Animal()
{
    std::cout << "Animal Destructor Called For " << getType() << std::endl;
}
