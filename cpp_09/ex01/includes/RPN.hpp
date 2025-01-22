#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN {

    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const RPN &src);
        const RPN& operator=(const RPN &other);
        ~RPN();

        
        void push(int value);
        void pop();
        int top();
        void calculateRPN(std::string expression);
};

#endif