#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "iostream"

class ScalarConverter {
    public:
        static void convert(std::string const &str);
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();
};

#endif
