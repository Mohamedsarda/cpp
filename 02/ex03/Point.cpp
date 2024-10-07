#include "Point.hpp"

Point::Point(const Point &copy)
{
    *this = copy;
    // std::cout << "Copy constructor Called" << std::endl;
}

Point::Point(const float x, const float y)
{
    this->x = x;
    this->y = y;
    // std::cout << "Two floating-point constructor called" << std::endl;
}

Point::Point()
{
    x = 0;
    y = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Point::~Point()
{
    // std::cout << "Destructor Called" << std::endl;
}

// getters

Fixed Point::getX() const
{
    return (this->x);
}

Fixed Point::getY() const
{
    return (this->y);
}