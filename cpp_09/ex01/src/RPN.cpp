#include "../includes/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

const RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::push(int value)
{
    this->_stack.push(value);
}

void RPN::pop()
{
    this->_stack.pop();
}

int RPN::top()
{
    return this->_stack.top();
}

void RPN::calculateRPN(std::string expression)
{
    std::istringstream ss(expression);
    std::string token;
    int value;
    while (ss >> token)
    {
        if (this->_stack.size() < 2 && (token == "*" || token == "/" || token == "+" || token == "-"))
        {
            std::cerr << "Error" << std::endl;
            return ; 
        }
        if (token == "*")
        {
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(a * b);
        }
        else if (token == "/")
        {
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            if (a == 0)
            {
                std::cerr << "Error: Division by zero" << std::endl;
                return;
            }
            this->_stack.push(b / a);
        }
        else if (token == "+")
        {
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(a + b);
        }
        else if (token == "-")
        {
            int a = this->_stack.top();
            this->_stack.pop();
            int b = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(b - a);
        }
        else
        {
            std::stringstream ss(token);
            ss >> value;
            if (value >= 10)
            {
                std::cerr << "Error: all values must be less than 10" << std::endl;
                return;
            }
            this->_stack.push(value);
        }
    }
    std::cout << this->_stack.top() << std::endl;
}