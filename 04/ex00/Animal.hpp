#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "iostream"

class Animal
{
    protected:
        std::string type;
    public:
        std::string    getType() const;
        void           setType(std::string _type);
        //
        virtual void   makeSound( void ) const;
        //
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        //
        Animal();
        Animal(std::string _type);
        // ~Animal();
        virtual ~Animal();
};

#endif