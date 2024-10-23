#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void    ff()
{
    system("leaks Animal");
}

int main()
{
    atexit(ff);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    // ...
    delete meta;
    delete i;
    delete j;
    WrongAnimal *anim = new WrongCat();
    anim->makeSound();
    delete anim;
    Dog rot("rot");
    rot.makeSound();
    return 0;
}