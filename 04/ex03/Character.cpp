#include "Character.hpp"

std::string const & Character::getName() const {
    return (this->type);
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++)
    {
        if (!amateria[i])
        {
            amateria[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {

    if (idx >= 0 && idx < 4 && amateria[idx] != NULL)
    {
        amateria[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3 || amateria[idx] == 0)
        return ;
    amateria[idx]->use(target);
}

//
Character &Character::operator=(const Character &copy) {
    if (this != &copy)
    {
        type = copy.getName();
        for (int i = 0; i < 4 ; i++)
        {
            if (amateria[i])
                delete amateria[i];
            amateria[i] = copy.amateria[i]->clone();
        }
    }
    return *this;
}

//
Character::Character(const std::string _type) {
    type = _type;
    for (int i = 0; i < 4 ; i++)
        amateria[i] = 0;
}

Character::Character(const Character &copy) {
    if (this != &copy)
    {
        type = copy.getName();
        for (int i = 0; i < 4 ; i++)
            amateria[i] = copy.amateria[i]->clone();
    }
}

Character::Character() {
    type = "Character";
    for (int i = 0; i < 4 ; i++)
        amateria[i] = 0;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete amateria[i];
}
