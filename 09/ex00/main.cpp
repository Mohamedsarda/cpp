#include "BitcoinExchange.hpp"

int main(int c, char **ar)
{
    if (c != 2)
    {
        std::cout << "To use The Program run : "; 
        std::cout << "./btc input.txt" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try {
        btc.Start(ar[1]);
        btc.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}