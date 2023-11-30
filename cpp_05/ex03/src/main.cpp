#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat b1("John", 151);
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if(rrf)
        rrf->beSigned(b1);
    delete rrf;
}