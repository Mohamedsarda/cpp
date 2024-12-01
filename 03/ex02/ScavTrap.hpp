#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        //
        void    guardGate();
        void attack(const std::string& target);
        //
        ScavTrap &operator=(const ScavTrap &copy);
        //
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        //

};


#endif
