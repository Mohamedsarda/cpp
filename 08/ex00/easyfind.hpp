#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "iostream"
#include <vector>

template <typename T>
typename T::const_iterator easyfind(T& container, int toFind) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), toFind);
    if (it == container.end())
        throw std::runtime_error("Element not found");
    return it;
}


#endif
