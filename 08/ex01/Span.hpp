#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
// #include <algorithm>
#include <limits>


class Span {
    private:
        unsigned int N;
        std::vector<int> container;
    public:
        Span(unsigned int _N);
        Span();
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        //
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void addNumber(int number);
        //
        int  longestSpan();
        int  shortestSpan();
};

template <typename T>
typename T::const_iterator ft_min_value(const T& container)
{
    if (container.empty())
        throw std::runtime_error("Container Empty");
    typename T::const_iterator min_value = container.begin();
    for (typename T::const_iterator begin = container.begin(); begin != container.end(); ++begin)
        if (*begin < *min_value)
            min_value = begin;
    return min_value;
}

template <typename T>
typename T::const_iterator ft_max_value(const T& container)
{
    if (container.empty())
        throw std::runtime_error("Container Empty");
    typename T::const_iterator max_value = container.begin();
    for (typename T::const_iterator begin = container.begin(); begin != container.end(); ++begin)
        if (*begin > *max_value)
            max_value = begin;
    return max_value;
}

template <typename T>
void ft_bubble_sort(T& container)
{
    typename T::iterator begin;
    typename T::iterator next;

    for (begin = container.begin(); begin != container.end(); ++begin)
    {
        for (next = container.begin(); next + 1 != container.end(); ++next)
            if (*next > *(next + 1))
                std::swap(*next, *(next + 1));
    }
}

#endif
