#include "Zombie.hpp"

void    Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name() const
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
    std::cout << "Destructor Called For : " << this->get_name() << std::endl;
}
