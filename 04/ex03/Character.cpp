#include "Character.hpp"

std::string const & Character::getName() {
    return (this->type);
}

void Character::equip(AMateria* m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {
    if (amateria[idx] == 0 || idx < 0 || idx > 3)
        return ;
    amateria[idx]->use(target);
}

//
Character &Character::operator=(const Character &copy) {

}

//
Character::Character(const std::string _type) {
    type = _type;
}

Character::Character(const Character &copy) {

}

Character::Character() {
    type = "Character";
    for (int i = 0; i < 4 ; i++)
        amateria[i] = 0;
}

Character::~Character() {

}
