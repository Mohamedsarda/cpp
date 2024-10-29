#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain
{
    public:
        std::string ideas[100];
        //
        Brain &operator=(const Brain &copy);
        //
        Brain(const Brain &copy);
        Brain();
        ~Brain();
};

#endif