#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("John", 151);
    b1.incrementGrade(100);
    b1.decrementGrade(150);

    /* << overload */
    std::cout << b1 << std::endl;

    Bureaucrat b2("Mary", 1);
    Form passport("passport", 10, 10);
    passport.beSigned(b2);
}