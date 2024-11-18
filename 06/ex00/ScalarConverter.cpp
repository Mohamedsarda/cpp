#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &str) {
    int i = 0;
    char c = '\0';
    double d = 0.0;
    float f = 0.0f;
    std::stringstream tmp(str);

    if (isChar(str)) {
        // Conversion from single character
        char a;
        tmp >> a;
        if (tmp.fail())
            throw "String Stream Failed To Convert";
        c = static_cast<char>(a);
        i = static_cast<int>(c);
        d = static_cast<double>(i);
        f = static_cast<float>(i);
    } else if (isInt(str)) {
        // Conversion from integer string
        int a;
        tmp >> a;
        if (tmp.fail())
            throw "String Stream Failed To Convert";
        i = static_cast<int>(a);
        d = static_cast<double>(i);
        f = static_cast<float>(i);
        c = (i >= 0 && i <= std::numeric_limits<char>::max() && isDisplayAble(static_cast<char>(i))) ? static_cast<char>(i) : '\0';
    } else if (isFloat(str)) {
        // Conversion from float string
        float a;
        tmp >> a;
        if (tmp.fail())
            throw "String Stream Failed To Convert";
        f = static_cast<float>(a);
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = (i >= 0 && i <= std::numeric_limits<char>::max() && isDisplayAble(static_cast<char>(i))) ? static_cast<char>(i) : '\0';
    } else if (isDouble(str)) {
        // Conversion from double string
        double a;
        tmp >> a;
        if (tmp.fail())
            throw "String Stream Failed To Convert";
        d = static_cast<double>(a);
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = (i >= 0 && i <= std::numeric_limits<char>::max() && isDisplayAble(static_cast<char>(i))) ? static_cast<char>(i) : '\0';
    }
    else
        throw "Invalid input format.";

        // Output with controlled formatting
        size_t dotPos = str.find('.');
        std::string afterDot = str.substr(dotPos + 1);
        std::cout << "char: "
                  << (c != '\0' && isDisplayAble(c) ? "'" + std::string(1, c) + "'" : "Non displayable")
                  << '\n';
        std::cout << "int: " << i << '\n';
        std::cout << std::fixed << std::setprecision(afterDot.length());
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << d << '\n';
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
    // if (points > 0) {
    //     size_t dotPos = str.find('.');
    //     std::string afterDot = str.substr(dotPos + 1);
    //     if (afterDot.length() > 10) return false;
    // }
    return true;
}

bool isDisplayAble(char c) {
    return (c >= 32 && c <= 126);
}
