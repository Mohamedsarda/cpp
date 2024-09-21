#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon      &gun;
        std::string name;
    public:
        void    attack();
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
};

#endif