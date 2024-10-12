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
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        //
        ClapTrap &operator=(const ClapTrap &copy);
        //
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();
};


#endif