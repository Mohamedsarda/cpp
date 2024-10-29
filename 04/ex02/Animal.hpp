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
         virtual void   makeSound() const = 0;
        //
        // virtual Animal &operator=(const Animal &copy);
        //
        // ~Animal();
        virtual ~Animal();
};

#endif