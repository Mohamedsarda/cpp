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
    //
    const Dog dog;
    Cat cat;
    dog.makeSound();
    cat.makeSound();
    //
    return 0;
}