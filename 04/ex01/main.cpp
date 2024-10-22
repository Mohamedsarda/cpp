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
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    // // ...
    // delete meta;
    delete i;
    // delete j;
    // Brain brain_1;
    // Cat cat_1;
    // Cat cat_2;
    // brain_1.ideas[0] = "med";
    // brain_1.ideas[1] = "sarda";
    // cat_1.brain = &brain_1;
    // cat_2 = cat_1;
    // std::cout << cat_1.brain->ideas[0] << std::endl;
    // std::cout << cat_1.brain->ideas[1] << std::endl;
    // std::cout << cat_2.brain->ideas[0] << std::endl;
    // std::cout << cat_2.brain->ideas[1] << std::endl;
    return 0;
}