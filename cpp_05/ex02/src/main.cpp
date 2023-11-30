#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat b1("Jany", 24);
    PresidentialPardonForm presidential("target1");
    RobotomyRequestForm robotomy("target2");
    ShrubberyCreationForm shrubbery("target3");

    presidential.beSigned(b1);
    presidential.execute(b1);

    robotomy.beSigned(b1);
    robotomy.execute(b1);

    shrubbery.beSigned(b1);
    shrubbery.execute(b1);
}