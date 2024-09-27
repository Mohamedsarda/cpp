#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

Zombie::Zombie(std::string name)
{
    std::cout << "Constructor Called" << std::endl;
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Destructor Called For : " << this->name << std::endl;
}
