#include "BitcoinExchange.hpp"

bool has30Days(int month) {
    return (month == 4 || month == 6 || month == 9 || month == 11);
}

bool has31Days(int month) {
    return (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;
}

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    (void)copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    (void)copy;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::Start(std::string const &arg) {
    readFromCsv("data.csv");
    readFromCsv(arg);
}

void BitcoinExchange::readFromCsv(std::string const &fileName) {
    std::ifstream out(fileName.c_str());
    if (!out)
        throw std::runtime_error("can't open file : " + fileName);
    std::string line;
    if (std::getline(out, line).fail()) {
        out.close();
        throw std::runtime_error("can't read from : " + fileName);
    }
    if ((fileName == "data.csv" && line != "date,exchange_rate") || (fileName != "data.csv" && line != "date | value")) {
        out.close();
        throw std::runtime_error("Please Check The header of " + fileName);
    }
    out.clear();
    if (out.eof())
        throw std::runtime_error(fileName + " there is not data in this file");
    if (fileName == "data.csv")
        ft_fill_data(out, this->data, line);
    else {
        bool isError;
        while (std::getline(out, line)) {
            isError = false;
            std::stringstream ss(line);
            std::string date;
            std::getline(ss, date, ' ');
            try {
                ft_check_date(date);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
                isError = true;
            }
            std::string value, mtp;
            double valueDouble;
            ss >> mtp >> value;
            std::stringstream ss1(value);
            ss1 >> valueDouble;
            if (valueDouble < 0) {
                if (isError)
                   std::cout << "Error: not a positive number. " << valueDouble << std::endl;
            }
            else {
                if (valueDouble > std::numeric_limits<int>::max()) {
                    std::cout << "Error: too large a number." << std::endl;
                    break;
                }
                std::string outPutDate;
                double outPutValue;
                std::map<std::string, double>::iterator it = data.begin();
                for (; it != data.end(); it++)
                {
                    if (it->first == date) {
                        outPutDate = it->first;
                        outPutValue = it->second;
                    }

                }
                if (it == data.end()) {
                    std::map<std::string, double>::iterator Upper_bound = data.upper_bound(date);
                    outPutDate = Upper_bound->first;
                    outPutValue = Upper_bound->second;
                }
                std::cout << outPutDate << " => " << outPutValue << " = " << valueDouble * outPutValue << std::endl;
            }
            line.clear();
        }
    }
    out.close();
    return ;
}

void ft_fill_data(std::ifstream &out, std::map<std::string, double> &map, std::string &line) {
    while (std::getline(out, line)) {
        std::stringstream ss(line);
        std::string date;
        std::getline(ss, date, ',');
        double value;
        ss >> value;
        ft_check_date(date);
        map[date] = value;
        line.clear();
    }
}

void ft_check_date(const std::string& line) {
    std::string year, month, day;
    std::stringstream ss(line);
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, '-');

    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        throw std::runtime_error("Error: Invalid date format : " + line);

    int _year = std::atoi(year.c_str());
    int _month = std::atoi(month.c_str());
    int _day = std::atoi(day.c_str());

    if (_year < 2009)
        throw std::runtime_error("Error: Invalid year : " + line);
    if (_month < 1 || _month > 12)
        throw std::runtime_error("Error: Invalid month : " + line);
    if (_day < 1)
        throw std::runtime_error("Error: Invalid day : " + line);

    if (has30Days(_month) && _day > 30)
        throw std::runtime_error("Error: Invalid day for a month with 30 days : " + line);
    if (has31Days(_month) && _day > 31)
        throw std::runtime_error("Error: Invalid day for a month with 31 days : " + line);

    if (_month == 2) {
        int maxDays = isLeapYear(_year) ? 29 : 28;
        if (_day > maxDays)
            throw std::runtime_error("Error: Invalid day for February : " + line);
    }
}


//
std::map<std::string, double> BitcoinExchange::getData(){
    return data;
}

void BitcoinExchange::print() {
    std::map<std::string , double> tmp = this->getData();
    std::map<std::string , double>::iterator begin = tmp.begin();
    std::map<std::string , double>::iterator end = tmp.end();
    for (;begin != end; begin++) {
        std::cout << begin->first << " " << begin->second << std::endl;
    }
}
