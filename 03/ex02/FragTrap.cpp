#include "FragTrap.hpp"

void    FragTrap::highFivesGuys( void )
{
    std::cout << getName() << " High Fives" << std::endl;
}
//
FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    if (this != &copy)
    {
        setName(copy.getName());
        set_Energy_Points(copy.get_Energy_Points());
        set_Hit_Points(copy.get_Hit_Points());
        set_Attack_Damage(copy.get_Attack_Damage());
    }
    std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
    return *this;
}
//
FragTrap::FragTrap()
{
    setName("FragTrap");
    set_Hit_Points(100);
    set_Energy_Points(100);
    set_Attack_Damage(30);
    std::cout << "FragTrap Default Constructor Called For " << getName() << std::endl; 
}

FragTrap::FragTrap(std::string name)
{
    setName(name);
    set_Hit_Points(100);
    set_Energy_Points(100);
    set_Attack_Damage(30);
    std::cout << "FragTrap Constructor Called For " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    setName(copy.getName());
    set_Energy_Points(copy.get_Energy_Points());
    set_Hit_Points(copy.get_Hit_Points());
    set_Attack_Damage(copy.get_Attack_Damage());
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called For " << getName() << std::endl;
}