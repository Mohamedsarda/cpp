#include "iostream"

int main(int c, char **ar)
{
    int i = 1;
    unsigned long j = 0;


    if (c < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    std::string tmp;
    while (i < c)
    {
        j = -1;
        tmp = ar[i];
        while (++j < tmp.length())
            tmp[j] = std::toupper(tmp[j]);
        std::cout << tmp << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}