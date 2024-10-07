#include "Point.hpp"

// Initialize fractionalBits to 256 directly
const int Fixed::fractionalBits = 1 << 8;

Fixed::Fixed()
{
    this->number = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

Fixed::Fixed(const int value)
{
    this->number = value * fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->number = roundf(value * fractionalBits);
}

// < > >= <= == !=

bool  Fixed::operator<(const Fixed &obj) const
{
    return (this->toFloat() < obj.toFloat());
}

bool  Fixed::operator>(const Fixed &obj) const
{
    return (this->toFloat() > obj.toFloat());
}

bool  Fixed::operator<=(const Fixed &obj) const
{
    return (this->toFloat() <= obj.toFloat());
}

bool  Fixed::operator>=(const Fixed &obj) const
{
    return (this->toFloat() >= obj.toFloat());
}

bool  Fixed::operator==(const Fixed &obj) const
{
    return (this->toFloat() == obj.toFloat());
}

bool  Fixed::operator!=(const Fixed &obj) const
{
    return (this->toFloat() != obj.toFloat());
}



// + -

Fixed Fixed::operator+( const Fixed &obj) const
{
    return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-( const Fixed &obj) const
{
    return Fixed(this->toFloat() - obj.toFloat());
}

// ++ --

Fixed &Fixed::operator--()
{
    this->number--;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed tmp(*this);
    this->number--;
    return tmp;
}


Fixed &Fixed::operator++()
{
    this->number++;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed tmp = *this;
    this->number++;
    return tmp;
}

//

Fixed &Fixed::operator=(Fixed const &obj)
{
    if (this != &obj)
        this->number = obj.number;
    return *this;
}

// * /

Fixed Fixed::operator/(Fixed const &obj) const
{
    return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed Fixed::operator*(Fixed const &obj) const
{
    return (Fixed(this->toFloat() * obj.toFloat()));
}

//

std::ostream &operator<<(std::ostream &out, const Fixed &a)
{
    out << a.toFloat();
    return (out);
}

Fixed::~Fixed()
{
}

//

int Fixed::getRawBits(void) const
{
    return this->number;
}

void Fixed::setRawBits(int const raw)
{
    this->number = raw;
}

//

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1.toFloat() > obj2.toFloat())
        return obj1;
    return obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1.toFloat() < obj2.toFloat())
        return obj1;
    return obj2;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1.toFloat() > obj2.toFloat())
        return obj1;
    return obj2;   
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if (obj1.toFloat() < obj2.toFloat())
        return obj1;
    return obj2;   
}

//

float Fixed::toFloat(void) const
{
    float value;

    value = (this->number * 1.0) / fractionalBits;
    return value;
}

int Fixed::toInt(void) const
{
    return this->number / fractionalBits;
}