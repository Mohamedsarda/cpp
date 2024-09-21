#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon      *gun;
        std::string name;
    public:
        void    attack();
        void    setWeapon(Weapon &gun);
        HumanB(std::string name);
        ~HumanB();
};

#endif