#include "ClapTrap.hpp"

int main()
{
    ClapTrap Med("Med");
    ClapTrap Sarda("Sarda");

    Med.attack(Sarda.getName());
    Sarda.takeDamage(Med.get_Attack_Damage());
    Sarda.beRepaired(90);
    return 0;
}