#include "PmergeMe.hpp"

void PmergeMe::ft_parse_arr(char **arr, int c) {
    for (int i = 1; i < c; i++)
    {
        std::stringstream ss(arr[i]);
        char extra;
        int num;
        if (!(ss >> num))
            throw std::runtime_error("Error : Can't Convert this number : " + ss.str());
        if (ss >> extra)
            throw std::runtime_error("Error: String contains extra characters : " + ss.str());
        if (num < 0)
            throw std::runtime_error("Error : Number must be negative");
        vectorList.push_back(num);
        dequeList.push_back(num);
    }
}
