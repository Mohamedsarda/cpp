#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        //
        void   makeSound( void ) const;
        //
        Cat &operator=(const Cat &copy);
        //
        Cat(std::string _type);
        Cat(const Cat &copy);
        Cat();
        ~Cat();
};

#endif