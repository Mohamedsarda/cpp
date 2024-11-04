#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        // std::string type;
        AMateria *amateria[4];
    public:
        //
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        //
        MateriaSource &operator=(const MateriaSource &copy);
        //
        MateriaSource(const std::string _type);
        MateriaSource(const MateriaSource &copy);
        //
        MateriaSource();
        ~MateriaSource();
};


#endif