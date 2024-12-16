#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "iostream"

class MutantStack {
    public :
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        MutantStack();
        ~MutantStack();
};

#endif
