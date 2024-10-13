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
    // Med1.attack(Sarda1.getName());
    // Sarda1.takeDamage(Med1.get_Attack_Damage());
    // Sarda1.beRepaired(90);
    // Med.attack(Sarda1.getName());
    // Sarda1.takeDamage(Med.get_Attack_Damage());
    // Sarda1.beRepaired(90);
    return 0;
}