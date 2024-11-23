#ifndef ITER_HPP
#define ITER_HPP

#include "iostream"

template <typename I> void iter(I *arr, size_t len, void (*func)(I &)) {
    if (!arr || !func)
        return ;
    size_t i = 0;
    while (i < len)
        func(arr[i++]);
}

template <typename I> void iter(I *arr, size_t len, void (*func)(const I &)) {
    if (!arr || !func)
        return ;
    size_t i = 0;
    while (i < len)
        func(arr[i++]);
}

#endif