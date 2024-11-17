#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &str) {

}

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter() {

}

bool isChar(const std::string str) {
    if (str.length() > 1)
        return false;
    return true;
}

bool isInt(const std::string str) {
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return false;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

bool isFloat(const std::string str) {

    return true;
}

bool isDouble(const std::string str) {

    return true;
}

bool isDisplayAble(char c) {
    return (c >= 32 && c <= 126);
}
