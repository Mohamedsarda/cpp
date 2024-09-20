#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

std::string Zombie::get_name()
{
    return (this->name);
}
void        Zombie::set_name(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{
    std::cout << "Constructor Called" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Destructor Called" << std::endl;
}
