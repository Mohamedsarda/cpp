#include "FragTrap.hpp"

int main()
{
    FragTrap Med("Med");
    FragTrap Sarda("Sarda");

    Med.attack(Sarda.getName());
    Sarda.takeDamage(Med.get_Attack_Damage());
    Sarda.beRepaired(20);
    Med.highFivesGuys();
    return 0;
}