#include "PmergeMe.hpp"


int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error : not enough parameters" << std::endl;
        return 1;
    }
    try {
        PmergeMe sorter;
        //
        sorter.ft_parse_arr(argv, argc);
        sorter.sort();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
