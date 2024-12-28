#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "iostream"
#include <stack>
#include <deque>
#include <vector>
#include <list>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack< T, Container>
{

    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) { }
        MutantStack&    operator=(const MutantStack& others) {
            std::stack< T, Container >::operator=(others);
            return *this;
        }
        typedef typename Container::iterator    iterator;
        iterator    begin() { return this->c.begin(); }
        iterator    end() { return this->c.end(); }
};

#endif
