#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename A> class Array
{
    private:
        unsigned int size;
        A *arr;
        /* data */
    public:
        unsigned int getSize() const;
        //
        Array();
        Array(unsigned int _size);
        Array(Array <A> &copy);
        Array <A> &operator=(Array <A> &copy);
        A &operator[](unsigned int &i);
        const A &operator[](unsigned int &i) const;
        ~Array();
};



#endif