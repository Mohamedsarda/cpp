#include "PmergeMe.hpp"

std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) return jacobsthal;
    
    jacobsthal.push_back(0);
    if (n == 1) return jacobsthal;
    jacobsthal.push_back(1);
    
    size_t i = 2;
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[i- 1] + 2 * jacobsthal[i- 2];
        jacobsthal.push_back(next);
        i++;
    }
    return jacobsthal;
}

std::vector<size_t> PmergeMe::generateInsertionPositions(size_t n) {
    std::vector<size_t> positions;
    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(n);
    
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        for (size_t pos = jacobsthal[i]; pos > jacobsthal[i-1]; pos--) {
            if (pos <= n) {
            }
        }
    }
    
    for (size_t i = 0; i < n; i++) {
        bool found = false;
        for (size_t j = 0; j < positions.size(); j++) {
            if (positions[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            positions.push_back(i);
        }
    }
    
    return positions;
}

void PmergeMe::ft_parse_arr(char **arr, int c) {
    for (int i = 1; i < c; i++) {
        std::stringstream ss(arr[i]);
        char extra;
        int num;
        if (!(ss >> num))
            throw std::runtime_error("Error: Can't convert this number: " + std::string(arr[i]));
        if (ss >> extra)
            throw std::runtime_error("Error: String contains extra characters: " + std::string(arr[i]));
        if (num < 0)
            throw std::runtime_error("Error: Number must be positive");
        vectorList.push_back(num);
        dequeList.push_back(num);
    }
}

struct ComparePairs {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.second < b.second;
    }
};

template <typename T>
void PmergeMe::binaryInsert(T& container, int value, size_t end) {
    typename T::iterator insertPos = std::lower_bound(container.begin(), 
                                                    container.begin() + end, 
                                                    value);
    container.insert(insertPos, value);
}

template <typename T>
void PmergeMe::ft_sort(T& container) {
    if (container.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    bool isOdd = container.size() % 2 != 0;
    int lastElement = 0;
    
    if (isOdd) {
        lastElement = container.back();
        container.pop_back();
    }

    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = container[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    std::sort(pairs.begin(), pairs.end(), ComparePairs());

    container.clear();
    std::vector<int> pendingElements;

    for (size_t i = 0; i < pairs.size(); ++i) {
        container.push_back(pairs[i].second);
        pendingElements.push_back(pairs[i].first);
    }

    std::vector<size_t> insertionOrder = generateInsertionPositions(pendingElements.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        size_t idx = insertionOrder[i];
        if (idx < pendingElements.size()) {
            binaryInsert(container, pendingElements[idx], idx + 1);
        }
    }

    if (isOdd) {
        typename T::iterator insertPos = std::lower_bound(container.begin(), 
                                                        container.end(), 
                                                        lastElement);
        container.insert(insertPos, lastElement);
    }
}

void PmergeMe::countTimeSpent(clock_t &start, bool isVector) {
    clock_t end = std::clock();
    double elapsedSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    long elapsedMicroseconds = static_cast<long>(elapsedSeconds * 1000000);
    std::cout << "Time to process a range of " << vectorList.size();
    std::cout << " elements with std::" << (isVector ? "vector" : "deque") << "<int> " << elapsedMicroseconds << " us" << std::endl;
} 

void PmergeMe::sort() {
    clock_t startVec = std::clock();
    ft_sort(vectorList);
    countTimeSpent(startVec, 1);
    clock_t startDeq = std::clock();
    ft_sort(dequeList);
    countTimeSpent(startDeq, 0);
}


void PmergeMe::printDeque() const {
    std::deque<int>::const_iterator it;
    for (it = dequeList.begin(); it != dequeList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVector() const {
    std::vector<int>::const_iterator it;
    for (it = vectorList.begin(); it != vectorList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

