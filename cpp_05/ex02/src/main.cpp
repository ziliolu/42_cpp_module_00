#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat b1("John", 24);
    RobotomyRequestForm ppf("Jack");
    
    ppf.beSigned(b1);
    ppf.execute(b1);
    ppf.execute(b1);

    /** para comecar o dia resolvendo erro*/
    /**
     * execute do Robotomy precisa falhar 50% das vezes
    */
}