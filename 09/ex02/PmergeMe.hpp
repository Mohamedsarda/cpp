#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <utility>

class PmergeMe {
    private:
        std::vector<int> vectorList;
        std::deque<int> dequeList;

        std::vector<size_t> generateJacobsthalNumbers(size_t n);
        std::vector<size_t> generateInsertionPositions(size_t n);
        
        template<typename T>
        void binaryInsert(T& container, int value, size_t end);

    public:
        PmergeMe() {}
        ~PmergeMe() {}

        void ft_parse_arr(char **arr, int c);
        template<typename T>
        void ft_sort(T& container);
        void sort();
        void printVector() const;
        void printDeque() const;
        void countTimeSpent(clock_t &start, bool isVector);

        const std::vector<int>& getVector() const { return vectorList; }
        const std::deque<int>& getDeque() const { return dequeList; }
};

#endif