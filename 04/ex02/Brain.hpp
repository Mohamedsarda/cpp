#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain
{
    private:
        std::string ideas[100];
    public:
        //
        Brain &operator=(const Brain &copy);
        //
        Brain(const Brain &copy);
        Brain();
        ~Brain();
};

#endif