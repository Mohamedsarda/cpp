#include "PmergeMe.hpp"

std::vector<size_t> PmergeMe::generateJacobsthalNumbers_vec(size_t n) {
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
    std::vector<size_t> reordered;

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current = jacobsthal[i];
        size_t previous = jacobsthal[i - 1];

        reordered.push_back(current);

        for (size_t j = current - 1; j > previous; --j)
            reordered.push_back(j);
    }

    return reordered;
}

std::deque<size_t> PmergeMe::generateJacobsthalNumbers_deq(size_t n) {
    std::deque<size_t> jacobsthal;
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
    std::deque<size_t> reordered;

    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current = jacobsthal[i];
        size_t previous = jacobsthal[i - 1];

        reordered.push_back(current);
        for (size_t j = current - 1; j > previous; --j)
            reordered.push_back(j);
    }

    return reordered;
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


void PmergeMe::ft_sort(std::vector<int> &container) {
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
        pairs.push_back(std::pair<int, int>(first, second));
    }

    std::sort(pairs.begin(), pairs.end(), ComparePairs());

    std::vector<size_t> insertionOrder = generateJacobsthalNumbers_vec(container.size());
    container.clear();
    std::vector<int> pendingElements;

    for (size_t i = 0; i < pairs.size(); ++i) {
        container.push_back(pairs[i].second);
        pendingElements.push_back(pairs[i].first);
    }
    if (pendingElements.size() > 0) {
        std::vector<int>::iterator pos1 = std::lower_bound(container.begin(), container.end(), pendingElements[0]);
        container.insert(pos1, pendingElements[0]);
    }
    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        size_t idx = insertionOrder[i];
        if (idx < pendingElements.size()) {
            std::vector<int>::iterator pos = std::lower_bound(container.begin(), container.end(), pendingElements[idx]);
            container.insert(pos, pendingElements[idx]);
        }
    }
    if (isOdd) {
        std::vector<int>::iterator insertPos = std::lower_bound(container.begin(),
                                                        container.end(),
                                                        lastElement);
        container.insert(insertPos, lastElement);
    }
}

void PmergeMe::ft_sort(std::deque<int> &container) {
    if (container.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
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

    std::deque<size_t> insertionOrder = generateJacobsthalNumbers_deq(container.size());
    container.clear();
    std::deque<int> pendingElements;

    for (size_t i = 0; i < pairs.size(); ++i) {
        container.push_back(pairs[i].second);
        pendingElements.push_back(pairs[i].first);
    }

    if (pendingElements.size() > 0) {
        std::deque<int>::iterator pos1 = std::lower_bound(container.begin(), container.end(), pendingElements[0]);
        container.insert(pos1, pendingElements[0]);
    }
    for (size_t i = 1; i < insertionOrder.size(); ++i) {
        size_t idx = insertionOrder[i];
        if (idx < pendingElements.size()) {
            std::deque<int>::iterator pos = std::lower_bound(container.begin(), container.end(), pendingElements[idx]);
            container.insert(pos, pendingElements[idx]);
        }
    }
    if (isOdd) {
        std::deque<int>::iterator insertPos = std::lower_bound(container.begin(),
                                                        container.end(),
                                                        lastElement);
        container.insert(insertPos, lastElement);
    }
}


void PmergeMe::sort(char **arr, int c) {
    clock_t start = clock();
    //
    ft_parse_arr(arr, c);
    std::cout << "Before: ";
    printDeque();
    //
    ft_sort(vectorList);
    clock_t endVec = clock();
    //
    ft_sort(dequeList);
    clock_t endDeq = clock();
    //
    std::cout << "After: ";
    printDeque();
    //
    long elapsedMicrosecondsVec = static_cast<long>(
            static_cast<double>(endVec - start) / CLOCKS_PER_SEC * 1000000);
    long elapsedMicrosecondsDeq = static_cast<long>(
            static_cast<double>(endDeq - start) / CLOCKS_PER_SEC * 1000000);
    // print
    std::cout << "Time to process a range of " << vectorList.size();
    std::cout << " elements with std::vector<int> " << elapsedMicrosecondsVec << " us" << std::endl;
    std::cout << "Time to process a range of " << dequeList.size();
    std::cout << " elements with std::deque<int> " << elapsedMicrosecondsDeq << " us" << std::endl;
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


//

PmergeMe::PmergeMe() {

}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy)
    {
        vectorList = copy.vectorList;
        dequeList = copy.dequeList;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    vectorList = copy.vectorList;
    dequeList = copy.dequeList;
}

PmergeMe::~PmergeMe() {

}
