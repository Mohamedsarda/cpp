#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->gun = NULL;
    this->name = name;
}
HumanB::~HumanB()
{

}

void    HumanB::setWeapon(Weapon &gun)
{
    this->gun = &gun;
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->gun->getType() << std::endl;
}