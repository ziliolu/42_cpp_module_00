#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("John", 100);
    b1.incrementGrade(100);
    b1.decrementGrade(150);

    /* << overload */
    std::cout << b1 << std::endl;
}