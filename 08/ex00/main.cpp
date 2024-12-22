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
            std::map<int, std::string> data;
            std::cout << data.size() << std::endl;
            data.insert(std::pair<int , std::string>(0, "med sarda"));
            std::pair<int , int> tmp;
            tmp.first = 0;
            tmp.second = 1;
            std::swap(tmp.first, tmp.second);
            std::cout << "hallo "<< tmp.first << std::endl;
            std::cout << data.begin()->second << std::endl;
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
