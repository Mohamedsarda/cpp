#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *copy) {
    for (int i = 0; i < 4; i++)
    {
        if (amateria[i] != NULL)
        {
            amateria[i] = copy;
            break ;
        }
    }
    delete copy;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
    {
        if (amateria[i]->getType() == type)
            return (amateria[i]);
    }
    return NULL;
}

//
MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
    if (this != &copy)
    {
        type = copy.type;
        for (int i = 0; i < 4; i++)
            amateria[i] = copy.amateria[i]->clone();
    }
    return *this;
}

//
MateriaSource::MateriaSource(const std::string _type) {
    type = _type;
    for (int i = 0; i < 4; i++)
        amateria[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
    if (this != &copy)
    {
        type = copy.type;
        for (int i = 0; i < 4; i++)
            amateria[i] = copy.amateria[i]->clone();
    }
}

//
MateriaSource::MateriaSource() {
    type = "MateriaSource";
    for (int i = 0; i < 4; i++)
        amateria[i] = 0;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete amateria[i];
}
