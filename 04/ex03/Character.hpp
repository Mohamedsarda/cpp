#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string type;
        AMateria *amateria[4];
    public:
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        //
        Character &operator=(const Character &copy);
        //
        Character(const std::string _type);
        Character(const Character &copy);
        Character();
        ~Character();
};

#endif