#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename A> class Array
{
    private:
        unsigned int size;
        A *arr;
        /* data */
    public:
        class ErrorSize : public std::exeption {
            public:
                const char *what() const throw {
                    return "Size should be bigger then 0 and smaller then the size";
                }
        }
        unsigned int getSize() const {
            return (size);
        }

        //
        Array() {
            size = 0;
            arr = new A[0];
        }

        Array(unsigned int _size) {
            arr = new A[_size];
        }

        Array(Array &copy) {
            arr = new A[0];
            *this = copy;
        }

        Array  &operator=(Array  &copy) {
            if (this != &copy)
            {
                delete arr;
                arr = new A;
                for (size_t i = 0; i < copy.size; i++)
                    arr[i] = copy.arr[i];
                size = copy.size;
            }
            return *this;
        }

        A &operator[](unsigned int &i) {
            if (i < 0 || i >= size)
                throw ErrorSize();
            return arr[i];
        }

        const A &operator[](unsigned int &i) const {
            if (i < 0 || i >= size)
                throw ErrorSize();
            return arr[i];
        }

        ~Array() {
            delete arr;
        }


};



#endif
