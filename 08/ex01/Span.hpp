#ifndef SPAN_HPP
#define SPAN_HPP

#include "iostream"
#include <vector>

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
};

#endif
