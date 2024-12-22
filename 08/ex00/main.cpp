#include "easyfind.hpp"

int main() {
    {
        try {
            std::vector<int> arr;
            for (int i = 0; i < 5; i++)
                arr.push_back(i);
            std::vector<int>::const_iterator it = easyfind(arr, 4);
            std::cout << "Found " << *it << std::endl;
        } catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::vector<int> arr;
            for (int i = 0; i < 10; i++)
                arr.push_back(i);
            std::vector<int>::const_iterator it = easyfind(arr, -5);
            std::cout << "Found " << *it << std::endl;
        } catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
