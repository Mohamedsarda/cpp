#include "Brain.hpp"

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain Copy Assignment Operator Called" << std::endl;
    return (*this);
}

//
Brain::Brain(const Brain &copy)
{
    *this = copy;
    std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain::Brain()
{
    std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}
