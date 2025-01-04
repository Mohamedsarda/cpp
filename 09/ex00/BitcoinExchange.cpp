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

void BitcoinExchange::readFromCsv(std::string const &fileName) {
    std::ifstream out(fileName);
    if (!out)
        throw std::runtime_error("can't open file : " + fileName);
    std::string line;
    if (std::getline(out, line).fail()) {
        out.close();
        throw std::runtime_error("can't read from : " + fileName);
    }
    if ((fileName == "data.csv" && line != "date,exchange_rate") || (fileName == "input.txt" && line != "date | value")) {
        out.close();
        throw std::runtime_error("Please Check The header of " + fileName);
    }
    out.clear();
    if (out.eof())
        throw std::runtime_error(fileName + " there is not data in this file");
    if (fileName == "data.csv")
    {
        while (std::getline(out, line)) {
            std::stringstream ss(line);
            std::string date;
            std::getline(ss, date, ',');
            double value;
            ss >> value;
            this->data[date] = value;
            line.clear();
        }
        out.close();
        return ;
    }
}


//
std::map<std::string, double> BitcoinExchange::getData(){
    return data;
}
