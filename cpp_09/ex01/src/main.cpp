#include "../includes/RPN.hpp"

int main(int arg, char **argv)
{
    if(arg != 2)
    {
        std::cout << "Usage: ./rpn \"[expression]\"" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.calculateRPN(argv[1]);
}