#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(16);
    std::cout << "Top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    // *****************************************
    {
        std::cout << "\n\tTest With Deque :" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout  << *it << "\t";
            ++it;
        }
        std::cout << "\n" << std::endl;
    }
    // *****************************************
    {
        std::cout << "\tTest With Vector :" << std::endl;
        MutantStack<std::string, std::vector<std::string> > vectorStack;
        vectorStack.push("string 1");
        vectorStack.push("string 2");
        vectorStack.push("string 3");
        MutantStack<std::string, std::vector<std::string> >::iterator vectorIt = vectorStack.begin();
        MutantStack<std::string, std::vector<std::string> >::iterator vectorEnd = vectorStack.end();
        for (;vectorIt != vectorEnd; vectorIt++)
            std::cout << *vectorIt << "\t";
        std::cout << "\n" << std::endl;
    }
    // *****************************************
    {
        std::cout << "\tTest With List :" << std::endl;
        MutantStack<std::string, std::list<std::string> > listStack;
        listStack.push("string 4");
        listStack.push("string 5");
        listStack.push("string 6");
        MutantStack<std::string, std::list<std::string> >::iterator listIt = listStack.begin();
        MutantStack<std::string, std::list<std::string> >::iterator listEnd = listStack.end();
        for (;listIt != listEnd; listIt++)
            std::cout << *listIt << "\t";
        std::cout << std::endl;
    }
    return 0;
}
