#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename A>
class Array
{
    private:
        unsigned int size;
        A *arr;

    public:
        class ErrorSize : public std::exception {
        public:
            const char *what() const throw() {
                return "Index is out of bounds";
            }
        };

        unsigned int getSize() const {
            return size;
        }

        // Default constructor
        Array() : size(0), arr(new A[0]) {}

        // Parameterized constructor
        Array(unsigned int _size) : size(_size), arr(new A[_size]) {}

        // Copy constructor
        Array(const Array &copy) : size(copy.size), arr(new A[copy.size]) {
            for (unsigned int i = 0; i < size; i++)
                arr[i] = copy.arr[i];
        }

        // Assignment operator
        Array &operator=(const Array &copy) {
            if (this != &copy) {
                delete[] arr;
                size = copy.size;
                arr = new A[size];
                for (unsigned int i = 0; i < size; i++)
                    arr[i] = copy.arr[i];
            }
            return *this;
        }

        // Subscript operator
        A &operator[](unsigned int i) {
            if (i >= size)
                throw ErrorSize();
            return arr[i];
        }

        // Const subscript operator
        const A &operator[](unsigned int i) const {
            if (i >= size)
                throw ErrorSize();
            return arr[i];
        }

        // Destructor
        ~Array() {
            delete[] arr;
        }
};

#endif
