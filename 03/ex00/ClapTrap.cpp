#include "ClapTrap.hpp"

//

void ClapTrap::attack(const std::string& target)
{
    if (_Energy_Points == 0)
    {
        std::cout << _Name << " have No Energy Left" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _Name << " attacks " << target << " , causing ? Points Of Damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    int i = (int)_Hit_Points - (int)amount;
    
    if (i < 0)
    {
        std::cout << "Can't Take That Much Damage" << std::endl;
        return ;
    }
    _Hit_Points -= amount;
    std::cout << _Name << "Took " << amount << " Damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount > 10)
    {
        std::cout << "You Can't Repair With More Then 10 Points" << std::endl;
        return ;
    }
    if (_Energy_Points == 0)
    {
        std::cout << "You Don't Have Any Energy Left You Can't Be Repaired" << std::endl;
        return ;
    }
    _Hit_Points = amount;
    _Energy_Points--;
    std::cout << _Name << "'s Health Was Repaired To " << amount << std::endl;
}

// constructor destructor
ClapTrap::ClapTrap(std::string name)
{
    _Name = name;
    _Hit_Points = 10;
    _Energy_Points = 10;
    _Attack_Damage = 0;
    std::cout << "Constructor Called For " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called For " << _Name << std::endl;
}
