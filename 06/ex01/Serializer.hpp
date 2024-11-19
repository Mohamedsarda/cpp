#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>

typedef struct s_data
{
    unsigned int number;
    std::string str;  
} t_data;

class Serializer
{
    private :
        Serializer();
    public :
        ~Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);
    
        static uintptr_t serialize(t_data* ptr);
        static t_data* deserialize(uintptr_t raw);
};


#endif