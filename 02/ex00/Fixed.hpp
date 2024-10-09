#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
    private:
        int number;
        static const int fractionalBits;
    public:
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        Fixed(const Fixed &obj);
        Fixed &operator=(Fixed const &obj);
        Fixed();
        ~Fixed();
};

#endif