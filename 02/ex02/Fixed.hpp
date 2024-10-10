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
        static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
        static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
        static  Fixed &max(Fixed &obj1, Fixed &obj2);
        static  Fixed &min(Fixed &obj1, Fixed &obj2);
        //
        Fixed(const Fixed &obj);
        Fixed(const int value);
        Fixed(const float value);
        //
        bool  operator<(const Fixed &obj) const;
        bool  operator>(const Fixed &obj) const;
        bool  operator<=(const Fixed &obj) const;
        bool  operator>=(const Fixed &obj) const;
        bool  operator==(const Fixed &obj) const;
        bool  operator!=(const Fixed &obj) const;

        Fixed &operator++();
        Fixed operator++( int );
        Fixed &operator--();
        Fixed operator--( int );

        Fixed operator+( const Fixed &obj) const;
        Fixed operator-( const Fixed &obj) const;
        Fixed operator/(Fixed const &obj) const;
        Fixed operator*(Fixed const &obj) const;
        Fixed &operator=(Fixed const &obj);
        //
        Fixed();
        ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &a);

#endif