#include "RPN.hpp"

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

double RPN::ft_run_operator(double num2, double num1, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '*': return num1 * num2;
        case '-': return num1 - num2;
        case '/':
            if (num2 == 0)
                throw std::runtime_error("Error: Cannot divide by zero");
            return num1 / num2;
        default: return 0;
    }
}

void RPN::start(const std::string& input) {
    std::string token;
    std::stringstream ss(input);

    while (ss >> token && !ss.fail()) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (this->numbers.size() < 2)
                throw std::runtime_error("Error: Insufficient operands for operation");

            double num2 = this->numbers.top(); this->numbers.pop();
            double num1 = this->numbers.top(); this->numbers.pop();
            double result = ft_run_operator(num2, num1, token[0]);
            this->numbers.push(result);
        } else {
            try {
                double num;
                std::stringstream tmp(token);
                tmp >> num;
                this->numbers.push(num);
            } catch (...) {
                throw std::runtime_error("Error: Invalid token [" + token + "]");
            }
        }
    }

    if (this->numbers.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression");

    std::cout << this->numbers.top() << std::endl;
}


//


RPN::RPN() {

}

RPN &RPN::operator=(const RPN &copy) {
    if (this != &copy)
        numbers = copy.numbers;
    return *this;
}

RPN::RPN(const RPN &copy) {
    numbers = copy.numbers;
}

RPN::~RPN() {

}
