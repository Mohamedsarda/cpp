#include "iter.hpp"

template <typename I>
void ft_print(const I &a)
{
    std::cout << a << " ";
}

template <typename I>
void ft_addone(I &a)
{
    a++;
}

int main()
{
    int arr[] = {0, 10, -1, 12, 15};
    ::iter(arr, 5, ft_print);
    std::cout << std::endl;
    ::iter(arr, 5, static_cast<void(*)(int&)>(ft_addone));
    ::iter(arr, 5, ft_print);
    std::cout << std::endl;
}