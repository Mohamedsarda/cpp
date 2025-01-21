#ifndef PRN_H
#define PRN_H

#include <stack>
#include <sstream>
#include <exception>
#include <cctype>
#include <iostream>
#include <string>


class RPN {
    private:
        std::stack<int> numbers;
    public:
        RPN();
        RPN &operator=(const RPN &copy);
        RPN(const RPN &copy);
        ~RPN();
        //
        int  ft_run_operator(int num2, int num1, char op);
        void    start(const std::string& input);
        bool    isOperator(char c);
};

#endif
