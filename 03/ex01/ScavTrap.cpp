#include "ScavTrap.hpp"

void    ScavTrap::guardGate()
{
    std::cout << getName() << " Is Now In Gate Keeper Mode" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if (get_Energy_Points() <= 0 || get_Hit_Points() <= 0)
    {
        std::cout << getName() << " Can't Attack Without Energy Or Hit Points :ScavTrap:" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << getName() << " attacks ";
    std::cout << target << " , causing "<< get_Attack_Damage() <<" Points Of Damage" << std::endl;
    set_Energy_Points(get_Energy_Points() - 1);
}
//
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if (this != &copy)
    {
        setName(copy.getName());
        set_Attack_Damage(copy.get_Attack_Damage());
        set_Energy_Points(copy.get_Energy_Points());
        set_Hit_Points(copy.get_Hit_Points());
    }
    std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
    return *this;
}

//
ScavTrap::ScavTrap(std::string name)
{
    setName(name);
    set_Hit_Points(100);
    set_Energy_Points(50);
    set_Attack_Damage(20);
    std::cout << "ScavTrap Constructor Called For " << name << std::endl; 
}

ScavTrap::ScavTrap()
{
    setName("ScavTrap");
    set_Hit_Points(100);
    set_Energy_Points(50);
    set_Attack_Damage(20);
    std::cout << "ScavTrap Default Constructor Called For " << getName() << std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    setName(copy.getName());
    set_Energy_Points(copy.get_Energy_Points());
    set_Hit_Points(copy.get_Hit_Points());
    set_Attack_Damage(copy.get_Attack_Damage());
    std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called For " << getName() << std::endl;
}