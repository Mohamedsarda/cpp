#include "Span.hpp"

Span::Span(unsigned int _N) {
    N = _N;
}

Span::Span() {}

Span::~Span() {}

Span::Span(const Span &copy) {
    if (this != &copy)
        *this = copy;
}

Span &Span::operator=(const Span &copy) {
    if (this != &copy)
    {
        if (N != 0)
            container.clear();
        N = copy.N;
        for (unsigned int i = 0; i < copy.container.size(); i++)
            container.push_back(copy.container[i]);
    }
    return *this;
}

void Span::addNumber(int number) {
    if (container.size() == N) {
        throw std::runtime_error("This Container Is Full");
    }
    container.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int distance = std::distance(begin, end);
    if (distance + container.size() > N) {
        throw std::runtime_error("This Container Is Full");
    }
    container.insert(container.end(), begin, end);
}