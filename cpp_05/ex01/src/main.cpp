#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("John", 3);
    Form form1("passport", 10, 15);

    b1.incrementGrade(1);
    std::cout << b1 << std::endl;
    b1.decrementGrade(1);
    std::cout << b1 << std::endl;
    std::cout << form1 << std::endl;
    form1.beSigned(b1);
    std::cout << form1 << std::endl;

    std::cout << std::endl << "---------- Exception Test ------------" << std::endl << std::endl;
    
    Bureaucrat b2("Mary", 100);
    Form form2("passport", 10, 15);
    b2.incrementGrade(10);
    std::cout << b2 << std::endl;
    b2.decrementGrade(61);
    std::cout << b2 << std::endl;
    std::cout << form2 << std::endl;
    form2.beSigned(b2);
    std::cout << form2 << std::endl;
}