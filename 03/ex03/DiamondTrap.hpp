#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _Name;
    public:
        //
        void        setDiamondTrapName(std::string Name);
        std::string getDiamondTrapName( void ) const ;
        //
        void    whoAmI();
        //
        DiamondTrap &operator=(const DiamondTrap &copy);
        //
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();
        //
        
};


#endif