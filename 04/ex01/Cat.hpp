#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        //
        void   makeSound( void ) const override;
        //
        Cat &operator=(const Cat &copy);
        //
        Cat(std::string _type);
        Cat(const Cat &copy);
        Cat();
        ~Cat();
};

#endif