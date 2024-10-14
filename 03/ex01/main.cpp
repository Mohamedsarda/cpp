#include "ScavTrap.hpp"

int main()
{
    ScavTrap Med("Med");
    ScavTrap Sarda("Sarda");
    // ScavTrap Med1("Med1");
    // ScavTrap Sarda1("Sarda1");

    Med.attack(Sarda.getName());
    Sarda.takeDamage(Med.get_Attack_Damage());
    Sarda.beRepaired(20);
    Sarda.guardGate();
    return 0;
}