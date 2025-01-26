#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <limits>

class PmergeMe {
    private:
        std::vector<int> vectorList;
        std::deque<int> dequeList;

        std::vector<size_t> generateJacobsthalNumbers_vec(size_t n);
        std::deque<size_t> generateJacobsthalNumbers_deq(size_t n);

    public:
        PmergeMe();
        PmergeMe &operator=(const PmergeMe &copy);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();

        void ft_parse_arr(char **arr, int c);
        void ft_sort(std::deque<int> &container);
        void ft_sort(std::vector<int> &container);
        void sort(char **arr, int c);
        void printVector() const;
        void printDeque() const;

        const std::vector<int>& getVector() const { return vectorList; }
        const std::deque<int>& getDeque() const { return dequeList; }
};

#endif
