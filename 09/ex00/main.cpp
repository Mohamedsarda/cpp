#include "BitcoinExchange.hpp"

int main(int c, char **ar)
{
    (void)ar;
    if (c != 2)
    {
        std::cout << "To use The Program run : "; 
        std::cout << "./btc input.txt" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try {
        btc.readFromCsv("data.csv");
        std::map<std::string , double> tmp = btc.getData();
        std::map<std::string , double>::iterator begin = tmp.begin();
        std::map<std::string , double>::iterator end = tmp.end();
        for (;begin != end; begin++) {
            std::cout << begin->first << " " << begin->second << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}