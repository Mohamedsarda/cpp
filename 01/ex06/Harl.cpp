#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{

}

void Harl::complain( std::string level )
{
    void    (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    std::string Levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (Levels[i] == level)
         break ;
    }
    switch (i)
    {
        case 0:
            while (i < 4)
                (this->*functions[i++])();
            break ;
        case 1:
            while (i < 4)
                (this->*functions[i++])();
            break ;
        case 2:
            while (i < 4)
                (this->*functions[i++])();
            break ;
        case 3:
            while (i < 4)
                (this->*functions[i++])();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            return ;
    }
    return ;
}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}
void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more\n" << std::endl;
}
void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}