#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat b1("John", 1);
    AForm* rrf;
    AForm* rrf2;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if(rrf)
    {
        rrf->beSigned(b1);
        b1.executeForm(*rrf);
        std::cout << *rrf << std::endl;
    }
    delete rrf;

    std::cout << std::endl << "---------- Error Test ------------" << std::endl << std::endl;
    
    Bureaucrat b2("Mary", 25);
    rrf2 = someRandomIntern.makeForm("presidential pard", "Zender");
}