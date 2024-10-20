#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        //
        void   makeSound( void ) const override;
        //
        Dog &operator=(const Dog &copy);
        //
        Dog(std::string _type);
        Dog(const Dog &copy);
        Dog();
        ~Dog();
};

#endif