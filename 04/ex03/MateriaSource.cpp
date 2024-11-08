#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *copy) {
    for (int i = 0; i < 4; i++)
    {
        if (amateria[i] == NULL)
        {
            amateria[i] = copy->clone();
            break ;
        }
    }
    delete copy;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++)
    {
        if (amateria[i]->getType() == type && amateria[i] != NULL)
            return (amateria[i]->clone());
    }
    return NULL;
}

//
MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
    if (this != &copy)
    {
        for (int i = 0; i < 4 ; i++)
        {
            if (amateria[i])
            {
                delete amateria[i];
                amateria[i] = NULL;
            }
            if (copy.amateria[i])
                amateria[i] = copy.amateria[i]->clone();
        }
    }
    return *this;
}

//
// MateriaSource::MateriaSource(const std::string _type) {
//     for (int i = 0; i < 4; i++)
//         amateria[i] = 0;
// }

MateriaSource::MateriaSource(const MateriaSource &copy) {
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (copy.amateria[i])
                amateria[i] = copy.amateria[i]->clone();
        }
    }
}

//
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        amateria[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete amateria[i];
}
