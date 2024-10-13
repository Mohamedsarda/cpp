#include "ClapTrap.hpp"

//

void ClapTrap::attack(const std::string& target)
{
    if (get_Energy_Points() <= 0 || get_Hit_Points() <= 0)
    {
        std::cout << getName() << " have No Energy Left" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << getName() << " attacks ";
    std::cout << target << " , causing "<< get_Attack_Damage() <<" Points Of Damage" << std::endl;
    set_Energy_Points(get_Energy_Points() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{    
    if (amount > get_Hit_Points())
    {
        std::cout << "Can't Take That Much Damage" << std::endl;
        return ;
    }
    set_Hit_Points(get_Hit_Points() - amount);
    std::cout << getName() << " Took " << amount << " Damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ((amount + get_Hit_Points()) > 100)
    {
        std::cout << "You Can't Repair With More Then 100 Points" << std::endl;
        return ;
    }
    if (get_Energy_Points() <= 0)
    {
        std::cout << getName() << " doesn't have any energy left; you can't be repaired" << std::endl;
        return ;
    }
    set_Hit_Points(get_Hit_Points() + amount);
    set_Energy_Points(get_Energy_Points() - 1);
    std::cout << getName() << "'s Health Was Repaired To " << get_Hit_Points() << std::endl;
}

// constructor destructor
ClapTrap::ClapTrap(std::string name)
{
    setName(name);
    set_Hit_Points(10);
    set_Energy_Points(10);
    set_Attack_Damage(0);
    std::cout << "Constructor Called For " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    setName(copy.getName());
    set_Energy_Points(copy.get_Energy_Points());
    set_Hit_Points(copy.get_Hit_Points());
    set_Attack_Damage(copy.get_Attack_Damage());
    std::cout << "Copy Constructor Called" << std::endl;
}


ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    if (this != &copy)
    {
        setName(copy.getName());
        set_Energy_Points(copy.get_Energy_Points());
        set_Hit_Points(copy.get_Hit_Points());
        set_Attack_Damage(copy.get_Attack_Damage());
    }
    std::cout << "Copy Assignment Operator Called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor Called For " << getName() << std::endl;
}



// getters and setters

std::string ClapTrap::getName() const
{
    return (_Name);
}

unsigned int    ClapTrap::get_Hit_Points() const
{
    return (_Hit_Points);
}

unsigned int    ClapTrap::get_Energy_Points() const
{
    return (_Energy_Points);
}

unsigned int    ClapTrap::get_Attack_Damage() const
{
    return (_Attack_Damage);
}

//

void        ClapTrap::setName(std::string Name)
{
    _Name = Name;
}

void        ClapTrap::set_Hit_Points(unsigned int Hit_Points)
{
    _Hit_Points = Hit_Points;
}

void        ClapTrap::set_Energy_Points(unsigned int Energy_Points)
{
    _Energy_Points = Energy_Points;
}

void        ClapTrap::set_Attack_Damage(unsigned int Attack_Damage)
{
    _Attack_Damage = Attack_Damage;
}
