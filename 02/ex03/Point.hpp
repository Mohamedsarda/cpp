#ifndef POINT_H
#define POINT_H

#include "iostream"
#include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Fixed getX() const;
        Fixed getY() const;
        //
        Point &operator=(const Point &copy);
        //
        Point();
        Point(const Point &copy);
        Point(const float x, const float y);
        //
        ~Point();
};


#endif