#ifndef B
#define B

#include "iostream"
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange 
{
    private:
        std::map<std::string, double> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();
        void readFromCsv(std::string const &fileName);
        //
        std::map<std::string, double> getData();
        void    fill_data_map(const std::ifstream &out);
};

bool has30Days(int month);
bool has31Days(int month);
bool isLeapYear(int year);

#endif