#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "iostream"

class ClapTrap
{
    private:
        std::string     _Name;
        unsigned int    _Hit_Points;
        unsigned int    _Energy_Points;
        unsigned int    _Attack_Damage;
    public:
        //
        std::string     getName() const ;
        unsigned int    get_Hit_Points() const;
        unsigned int    get_Energy_Points() const;
        unsigned int    get_Attack_Damage() const;
        //
        void        setName(std::string Name);
        void        set_Hit_Points(unsigned int Hit_Points);
        void        set_Energy_Points(unsigned int Energy_Points);
        void        set_Attack_Damage(unsigned int Attack_Damage);
        //
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        //
        ClapTrap &operator=(const ClapTrap &copy);
        //
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();
};


#endif