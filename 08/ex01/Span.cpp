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

int  Span::longestSpan() {
    std::vector<int>::const_iterator maxValue = ft_max_value(container);
    std::vector<int>::const_iterator minValue = ft_min_value(container);
    return *maxValue - *minValue;
}

int Span::shortestSpan() {
    if (container.size() < 2)
        throw std::logic_error("Not enough elements to calculate a span");
    ft_bubble_sort(container);
    int shortest = 2147483647;
    for (size_t i = 1; i < container.size(); ++i) {
        int diff = container[i] - container[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }

    return shortest;
}
