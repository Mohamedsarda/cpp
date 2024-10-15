#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap Med("Med");
    DiamondTrap Sarda("Sarda");

    Med.attack(Sarda.getName());
    Sarda.takeDamage(Med.get_Attack_Damage());
    Sarda.beRepaired(20);
    Med.highFivesGuys();
    return 0;
}