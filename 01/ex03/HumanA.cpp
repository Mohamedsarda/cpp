#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : gun(weapon)
{
    this->name = name;
}
HumanA::~HumanA()
{

}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->gun.getType() << std::endl;
}