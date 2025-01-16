#include "PmergeMe.hpp"

int main(int c, char **arr) {
    if (c == 1)
    {
        std::cerr << "Error : to run the Program use :" << arr[0] << " <Numbers to sort>" << std::endl;
        return 1;
    }
    try {
        PmergeMe data;
        data.ft_parse_arr(arr, c);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
