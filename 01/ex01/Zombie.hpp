#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"

class Zombie{
    private:
        std::string name;
    public:
        std::string get_name() const;
        void        set_name(std::string name);
        void announce( void );
        Zombie();
        ~Zombie();
};

Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif