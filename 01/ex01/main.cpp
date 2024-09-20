#include "Zombie.hpp"

int main()
{
    Zombie  *zomb;
    int     N = 5;

    //
    zomb = zombieHorde(N , "Med sarda");
    for (int i = 0; i < N; i++)
    {
        zomb[i].announce();
    }
    delete[] zomb;

    return (0);
}