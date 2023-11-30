#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat b1("John", 3);
    b1.incrementGrade(1);
    std::cout << b1 << std::endl;
    b1.decrementGrade(1);
    std::cout << b1 << std::endl;

    std::cout << std::endl << "---------- Exception Test ------------" << std::endl << std::endl;
    Bureaucrat b2("Mary", 100);
    b2.incrementGrade(10);
    std::cout << b2 << std::endl;
    b2.decrementGrade(61);
    std::cout << b2 << std::endl;
    
}