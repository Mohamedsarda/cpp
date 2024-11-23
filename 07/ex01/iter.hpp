#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template <typename I, typename T> void iter(I *arr, size_t len, void (*func)(T &)) {
    if (!arr || !func)
        return ;
    for (size_t i = 0; i < len ; i++)
        func(arr[i]);
}

#endif
