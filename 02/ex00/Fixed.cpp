#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(Fixed const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->number = obj.number;
    return *this;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number);
}

void Fixed::setRawBits( int const raw )
{
    this->number = raw;
}
