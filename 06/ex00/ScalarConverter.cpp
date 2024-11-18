#include "ScalarConverter.hpp"
#include <sstream>

void ScalarConverter::convert(std::string const &str) {
    int i = 0;
    char c = '\0';
    double d = 0.0;
    float f = 0.0f;
    std::stringstream string(str);

    if (isChar(str))
    {
        char tmp;
        string >> tmp;
        if (string.fail())
            throw "Something went wrong when trying to convert to char";
        i = static_cast<int>(tmp);
        d = static_cast<double>(i);
        f = static_cast<float>(i);
        c = static_cast<char>(i);
    }
    std::cout << c << std::endl;
    std::cout << i << std::endl;
    std::cout << d << std::endl;
    std::cout << f << std::endl;
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

bool isChar(const std::string &str) {
    if (str.length() != 1)
        return false;
    return true;
}

bool isInt(const std::string &str) {
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


bool isFloat(const std::string &str) {
    bool hasDigit = false;
    bool hasPoint = false;
    bool hasF = false;
    size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '.') {
        hasPoint = true;
        i++;
    }
    for (; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (hasPoint) return false;
            hasPoint = true;
        }
        else if (str[i] == 'f') {
            if (hasF) return false;
            hasF = true;
        }
        else if (str[i] < '0' || str[i] > '9')
            return false;
        else
            hasDigit = true;
    }
    if (!hasDigit) return false;
    if (hasF && str[str.length() - 1] != 'f') return false;
    return true;
}

bool isDouble(const std::string &str) {
    int points = 0;
    bool hasDigit = false;
    size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[str.length() - 1] == '.')
        return false;
    for (; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (points > 0) return false;
            points++;
        }
        else if (str[i] < '0' || str[i] > '9')
            return false;
        else
            hasDigit = true;
    }

    if (!hasDigit) return false;
    if (points > 0) {
        size_t dotPos = str.find('.');
        std::string afterDot = str.substr(dotPos + 1);
        if (afterDot.length() > 10) return false;
    }
    return true;
}

bool isDisplayAble(char c) {
    return (c >= 32 && c <= 126);
}
