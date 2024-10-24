#ifndef WRONGANIMAL
#define WRONGANIMAL

#include "iostream"

class WrongAnimal
{
    protected:
        std::string type;
    public:
        //
        std::string getType() const;
        void setType(std::string _type);
        //
        void makeSound( void ) const;
        //
        WrongAnimal &operator=(const WrongAnimal &copy);
        //
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal(std::string _type);
        //
        WrongAnimal();
        virtual ~WrongAnimal();
};

#endif