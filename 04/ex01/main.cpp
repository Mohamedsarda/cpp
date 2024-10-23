#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void    ff()
{
    system("leaks Animal");
}

int main()
{
    atexit(ff);
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    //
    int N = 6;
    int a = 0;
    const Animal *arr[N];

    // Fill the first half with Dog objects
    while (a < (N / 2))
    {
        arr[a] = new Dog();
        arr[a]->makeSound();
        a++;
    }

    // Fill the second half with Cat objects
    while (a < N)
    {
        arr[a] = new Cat();
        arr[a]->makeSound();
        a++;
    }

    // Delete all the objects
    for (int i = 0; i < N; i++)
        delete arr[i];
    //
    return 0;
}