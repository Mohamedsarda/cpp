#include "Zombie.hpp"

int main()
{
    Zombie  *zomb;

    //
    zomb = newZombie("Med Sarda");
    zomb->announce();
    delete zomb;
    //
    randomChump("msarda");
    return (0);
}