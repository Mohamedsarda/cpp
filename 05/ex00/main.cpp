#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bur1("med", 145);
        Bureaucrat bur2("sarda", 150);
        std::cout << bur1 << std::endl;
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
        bur1.decrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}