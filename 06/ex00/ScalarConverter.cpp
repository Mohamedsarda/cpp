#include "ScalarConverter.hpp"
std::string intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}
void ScalarConverter::convert(std::string const &str) {
    int i = 0;
    char c = '\0';
    double d = 0.0;
    float f = 0.0f;

    // Handle special cases for floats and doubles
    if (str == "-inff" || str == "-inf") {
        f = -1.0f / 0.0f; // Negative infinity
        d = -1.0 / 0.0;   // Negative infinity
    } else if (str == "+inff" || str == "+inf") {
        f = 1.0f / 0.0f;  // Positive infinity
        d = 1.0 / 0.0;    // Positive infinity
    } else if (str == "nanf" || str == "nan") {
        f = 0.0f / 0.0f;  // NaN
        d = 0.0 / 0.0;    // NaN
    } else {
        // Process regular conversions
        std::stringstream tmp(str);

        if (isInt(str)) {
            int a;
            tmp >> a;
            if (tmp.fail())
                throw "String Stream Failed To Convert";
            i = a;
            d = static_cast<double>(i);
            f = static_cast<float>(i);
            c = (i >= 0 && i <= 127 && isDisplayAble(static_cast<char>(i))) ? static_cast<char>(i) : '\0';
        } else if (isChar(str)) {
            char a;
            tmp >> a;
            if (tmp.fail())
                throw "String Stream Failed To Convert";
            c = a;
            i = static_cast<int>(c);
            d = static_cast<double>(i);
            f = static_cast<float>(i);
        } else if (isFloat(str)) {
            float a;
            tmp.str(str.substr(0, str.length() - 1));
            tmp >> a;
            if (tmp.fail())
                throw "String Stream Failed To Convert";
            f = a;
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            c = (i >= 0 && i <= 127 && isDisplayAble(static_cast<char>(i))) ? static_cast<char>(i) : '\0';
        } else if (isDouble(str)) {
            double a;
            tmp >> a;
            if (tmp.fail())
                throw "String Stream Failed To Convert";
            d = a;
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            c = (i >= 0 && i <= 127 && isDisplayAble(static_cast<char>(i))) ? static_cast<char>(i) : '\0';
        } else {
            throw "Invalid input format.";
        }
    }

    // Output with controlled formatting
    std::cout << "char: "
              << (c != '\0' && isDisplayAble(c) ? "'" + std::string(1, c) + "'" : "Non displayable")
              << std::endl;
    std::cout << "int: "
              << ((d == 1.0 / 0.0 || d == -1.0 / 0.0 || d != d) ? "impossible" : intToString(i))
              << std::endl;
    std::cout << "float: " << f
              << ((f == static_cast<int>(f) && f == f && f != 1.0f / 0.0f && f != -1.0f / 0.0f) ? ".0f" : "f")
              << "\n";
    std::cout << "double: " << d
              << ((d == static_cast<int>(d) && d == d && d != 1.0 / 0.0 && d != -1.0 / 0.0) ? ".0" : "")
              << std::endl;
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
    return true;
}

bool isDisplayAble(char c) {
    return (c >= 32 && c <= 126);
}
