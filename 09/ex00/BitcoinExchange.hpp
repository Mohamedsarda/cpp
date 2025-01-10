#ifndef B
#define B

#include "iostream"
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <limits>

class BitcoinExchange
{
    private:
        std::map<std::string, double> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();
        //
        void Start(std::string const &arg);
        void print();
        void readFromCsv(std::string const &fileName);
        std::map<std::string, double> getData();
};

bool has30Days(int month);
bool has31Days(int month);
bool isLeapYear(int year);
void ft_fill_data(std::ifstream &out, std::map<std::string, double> &map, std::string &line);
void ft_check_date(const std::string& line);

#endif
