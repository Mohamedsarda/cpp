#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "iostream"
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria &operator=(const AMateria &copy);
        AMateria(std::string const & type);
        AMateria(const AMateria &copy);
        AMateria();
        virtual ~AMateria();
        //
        std::string const & getType() const; //Returns the materia type
        // void setType(std::string const type);
        //
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif;