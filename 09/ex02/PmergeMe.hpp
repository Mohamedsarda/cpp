#ifndef A
#define A

#include "iostream"
#include <sstream>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int> vectorList;
        std::deque<int> dequeList;
    public:
        void ft_parse_arr(char **arr, int c);
};

#endif
