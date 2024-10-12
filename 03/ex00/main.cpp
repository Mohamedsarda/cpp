#include "ClapTrap.hpp"

int main()
{
    ClapTrap Med("Med");
    ClapTrap Sarda("Sarda");

    Med.attack(Sarda.getName());
    Sarda.takeDamage(10);
    Sarda.beRepaired(10);
    return 0;
}