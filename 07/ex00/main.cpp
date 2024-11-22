#include "Whatever.hpp"
#include "iostream"

int main()
{
    {
        int a = 5;
        int b = 0;
        std::cout << "min(a, b) : " << min(a, b) << std::endl;
        std::cout << "max(a, b) : " << max(a, b) << std::endl;
        swap(a, b);
        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b << std::endl;
    }
    
}