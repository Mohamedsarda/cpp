#include "Point.hpp"

int main( void )
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point p1(1, 1); // Inside
    Point p2(5, 5); // Outside

    Point test = p2;

    std::cout << test << std::endl;

    if (bsp(a, b, c, p1))
        std::cout << "The Point is inside the triangle? " << std::endl;
    else
        std::cout << "The Point is outside the triangle? " << std::endl;
    return 0;
}
