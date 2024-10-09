#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Initialize fractionalBits to 256 directly
const int Fixed::fractionalBits = 8;

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

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->number = value * (1 << fractionalBits); // Multiply by 256
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(value * (1 << fractionalBits)); // Multiply by 256
}

Fixed &Fixed::operator=(Fixed const &obj)
{
    if (this != &obj)
        this->number = obj.number;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &a)
{
    out << a.toFloat();
    return (out);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->number;
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

float Fixed::toFloat(void) const
{
    // Convert fixed-point back to float by dividing by 256
    float value;

    value = (this->number * 1.0) / (1 << fractionalBits);
    return value;
}

int Fixed::toInt(void) const
{
    // Convert fixed-point back to int by dividing by 256
    return this->number / (1 << fractionalBits);
}

// 0000 0000 0010 1010
// 0000 0000 0101 0100
// 0000 0000 1010 1000
// 0000 0001 0101 0000
// 0000 0010 1010 0000
// 0000 0101 0100 0000
// 0000 1010 1000 0000
// 0001 0101 0000 0000