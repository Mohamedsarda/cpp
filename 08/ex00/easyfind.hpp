#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "iostream"
#include <vector>
#include <map>

template <typename T>
typename T::const_iterator easyfind(T& container, int toFind) {
    typename T::const_iterator begin = container.begin();
    typename T::const_iterator end = container.end();
    for (; begin != end ; begin++)
        if (*begin == toFind)
            return begin;
    throw std::runtime_error("Element not found");
}


#endif
