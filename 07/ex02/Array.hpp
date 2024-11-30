#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename A> class Array
{
    private:
        unsigned int size;
        A *arr;
    public:
        class ErrorSize : public std::exception {
            public:
                const char *what() const throw() {
                    return "Size should be bigger then 0 and smaller then the size";
                }
        };
        unsigned int getSize() const {
            return (size);
        }

        //
        Array() {
            size = 0;
            arr = new A[0];
        }

        Array(unsigned int _size) {
            size = _size;
            arr = new A[_size];
        }

        Array(Array &copy) {
            size = copy.size;
            arr = NULL;
            *this = copy;
        }

        Array  &operator=(Array  &copy) {
            if (this != &copy)
            {
                if (arr != NULL)
                    delete[] arr;
                size = copy.size;
                arr = new A[size];
                for (size_t i = 0; i < copy.size; i++)
                    arr[i] = copy.arr[i];
            }
            return *this;
        }

        A &operator[](unsigned int i) {
            if (i < 0 || i >= size)
                throw ErrorSize();
            return arr[i];
        }

        ~Array() {
            delete[] arr;
        }


};



#endif
