#include "ScavTrap.hpp"

int main()
{
    ScavTrap Med("Med");
    ScavTrap Sarda("Sarda");

    Med.attack(Sarda.getName());
    Sarda.takeDamage(Med.get_Attack_Damage());
    Sarda.beRepaired(20);
    Sarda.guardGate();
    return 0;
}