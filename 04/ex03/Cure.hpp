#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        //
        Cure* clone() const;
        void use(ICharacter& target);
        //
        Cure(std::string const type);
        Cure(const Cure &copy);
        //
        Cure &operator=(const Cure &copy);
        //
        Cure();
        ~Cure();
};

#endif