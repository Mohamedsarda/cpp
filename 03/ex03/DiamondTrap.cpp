#include "DiamondTrap.hpp"

void        DiamondTrap::setDiamondTrapName(std::string Name)
{
    _Name = Name;
}
std::string DiamondTrap::getDiamondTrapName( void ) const 
{
    return (this->_Name);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "My Name Is : " << getDiamondTrapName() << "The ClapTrap Name is : " << ClapTrap::getName() << std::endl;
}

//
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    if (this != &copy)
    {
        setName(copy.getName());
        setDiamondTrapName(getDiamondTrapName());
        set_Energy_Points(copy.get_Energy_Points());
        set_Hit_Points(copy.get_Hit_Points());
        set_Attack_Damage(copy.get_Attack_Damage());
    }
    std::cout << "DiamondTrap Copy Assignment Operator Called" << std::endl;
    return *this;
}
//
DiamondTrap::DiamondTrap()
{
    setName("DiamondTrap_clap_name");
    setDiamondTrapName("DiamondTrap");
    set_Hit_Points(FragTrap::get_Hit_Points());
    set_Energy_Points(ScavTrap::get_Energy_Points());
    set_Attack_Damage(FragTrap::get_Attack_Damage());
    std::cout << "DiamondTrap Default Constructor Called For " << getDiamondTrapName() << std::endl; 
}
DiamondTrap::DiamondTrap(std::string name)
{
    setName(name + "_clap_name");
    setDiamondTrapName(name);
    set_Hit_Points(FragTrap::get_Hit_Points());
    set_Energy_Points(ScavTrap::get_Energy_Points());
    set_Attack_Damage(FragTrap::get_Attack_Damage());
    std::cout << "DiamondTrap Constructor Called For " << name << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    setName(copy.getName());
    setDiamondTrapName(copy.getDiamondTrapName());
    set_Energy_Points(copy.get_Energy_Points());
    set_Hit_Points(copy.get_Hit_Points());
    set_Attack_Damage(copy.get_Attack_Damage());
    std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor Called For " << getDiamondTrapName() << std::endl;
}