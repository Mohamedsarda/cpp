#include "Weapon.hpp"

std::string Weapon::getType()
{
    return this->type;
}

// Setter
void Weapon::setType(std::string type)
{
    this->type = type;
}

Weapon::Weapon() {}
Weapon::~Weapon() {}
Weapon::Weapon(std::string type)
{
    this->type = type;
}