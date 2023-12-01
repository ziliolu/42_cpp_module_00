#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "[INTERN] Default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
    (void)src;
    std::cout << "[INTERN] Copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "[INTERN] Destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
    std::cout << "[INTERN] Assignment operator called" << std::endl;
    (void)other;
    return (*this);
}

AForm *createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::makeForm(std::string formName, std::string target) const
{
    typedef AForm *(*funcPtr)(std::string target);
    std::cout << "[MAKING FORM...] ";
    std::string form_names[3] = {
        "presidential pardon", 
        "robotomy request",
        "shrubbery creation"
    };
    funcPtr form_functions[3] = {
        &createPresidentialPardonForm,
        &createRobotomyRequestForm,
        &createShrubberyCreationForm
    };

    for(int i = 0; i < 3; i++)
    {
        if(formName == form_names[i])
        {
            std::cout << formName << " was successfully created by Intern" << std::endl;
            return (form_functions[i])(target);
        }
    }
    std::cout << formName << " can't be created by Intern" << std::endl;
    return (NULL);
}