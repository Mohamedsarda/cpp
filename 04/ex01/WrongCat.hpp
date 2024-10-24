#ifndef WRONGCAT
#define WRONGCAT

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        //
        void makeSound( void ) const;
        //
        WrongCat &operator=(const WrongCat &copy);
        //
        WrongCat(const WrongCat &copy);
        //
        WrongCat(std::string _type);
        //
        WrongCat();
        ~WrongCat();
};

#endif