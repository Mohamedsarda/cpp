#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "iostream"

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        static void convert(std::string const &str);
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();
};

bool isChar(const std::string &str);
bool isInt(const std::string &str);
bool isFloat(const std::string &str);
bool isDouble(const std::string &str);
bool isDisplayAble(char c);

#endif
