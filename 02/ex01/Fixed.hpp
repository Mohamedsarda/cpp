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
        //
        float   toFloat( void ) const;
        int     toInt( void ) const;
        //
        Fixed(const Fixed &obj);
        Fixed(const int value);
        Fixed(const float value);
        //
        Fixed &operator=(Fixed const &obj);
        //
        Fixed();
        ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &a);

#endif