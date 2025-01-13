#include "BitcoinExchange.hpp"

bool has30Days(int month) {
    return (month == 4 || month == 6 || month == 9 || month == 11);
}

bool has31Days(int month) {
    return (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    data = copy.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy)
        data = copy.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::Start(const std::string &arg) {
    readFromCsv("data.csv");
    readFromCsv(arg);
}

void BitcoinExchange::readFromCsv(const std::string &fileName) {
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + fileName);

    std::string header;
    if (!std::getline(file, header) ||
        ((fileName == "data.csv" && header != "date,exchange_rate") ||
         (fileName != "data.csv" && header != "date | value"))) {
        throw std::runtime_error("Invalid header in file: " + fileName);
    }

    if (fileName == "data.csv")
        ft_fill_data(file, data);
    else {
        std::string line;
        while (std::getline(file, line)) {
            parseTransaction(line);
        }
    }
}

void BitcoinExchange::ft_fill_data(std::ifstream &file, std::map<std::string, double> &map) {
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        double value;

        std::getline(ss, date, ',');
        ss >> value;

        ft_check_date(date);
        map[date] = value;
    }
}

void BitcoinExchange::parseTransaction(const std::string &line) {
    std::stringstream ss(line);
    std::string date, valueStr, separator;
    double value;

    std::getline(ss, date, ' ');
    ss >> separator >> valueStr;

    if (separator != "|" || !(std::stringstream(valueStr) >> value)) {
        std::cerr << "Error: Invalid format in line: " << line << std::endl;
        return;
    }

    ft_check_date(date);

    if (value < 0) {
        std::cerr << "Error: Not a positive number: " << value << std::endl;
        return;
    }

    if (value > std::numeric_limits<int>::max()) {
        std::cerr << "Error: Number too large: " << value << std::endl;
        return;
    }

    std::map<std::string, double>::iterator it = data.lower_bound(date);
    if (it == data.end() || it->first != date)
        if (it != data.begin()) --it;

    double exchangeRate = (it != data.end()) ? it->second : 0;
    std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
}

void BitcoinExchange::ft_check_date(const std::string &line) {
    std::stringstream ss(line);
    std::string yearStr, monthStr, dayStr;

    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr, '-');

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (year < 2009)
        throw std::runtime_error("Error: Year out of range: " + line);

    if (month < 1 || month > 12)
        throw std::runtime_error("Error: Invalid month: " + line);

    if (day < 1 || (has30Days(month) && day > 30) || (has31Days(month) && day > 31) ||
        (month == 2 && day > (isLeapYear(year) ? 29 : 28))) {
        throw std::runtime_error("Error: Invalid day: " + line);
    }
}

std::map<std::string, double> BitcoinExchange::getData() {
    return data;
}

void BitcoinExchange::print() {
    for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}
