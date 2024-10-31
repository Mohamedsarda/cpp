#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        //
        Ice* clone() const;
        void use(ICharacter& target);
        //
        Ice &operator=(const Ice &copy);
        //
        Ice(const Ice &copy);
        Ice(std::string const type);
        //
        Ice();
        ~Ice();
};

#endif