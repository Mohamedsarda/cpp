#include "WrongCat.hpp"

void WrongCat::makeSound( void ) const
{
    std::cout << "Wrong Cat Sound" << std::endl;
}

//
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    if (this != &copy)
        setType(copy.getType());
    std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
    return (*this);
}

//
WrongCat::WrongCat(const WrongCat &copy)
{
    setType(copy.getType());
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}

//
WrongCat::WrongCat(std::string _type)
{
    setType(_type);
    std::cout << "WrongCat Constructor Called For " << getType() << std::endl;
}

//
WrongCat::WrongCat()
{
    setType("WrongCat");
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called For " << getType() << std::endl;
}
