#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 1)
    {
        std::cout << "The Number Of Zombies Should Be At least 1" << std::endl;
        return (NULL);
    }
    Zombie  *head = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        head[i].set_name(name);
    }
    return (head);
}
