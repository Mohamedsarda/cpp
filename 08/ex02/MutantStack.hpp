#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "iostream"
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>{
    public :
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
        MutantStack(const MutantStack &copy) : std::stack<T>(copy) { }
        MutantStack &operator=(const MutantStack &copy) {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return *this;
        }
        MutantStack() : std::stack<T>() {}
        ~MutantStack() { }
};

#endif
