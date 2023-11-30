//
// Created by lpicoli- on 11/29/23.
//

#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Requestomy", 72, 45), _target(target)
{
    std::cout << "[REQUESTOMY] Target constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
    std::cout << "[REQUESTOMY] Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "[REQUESTOMY] Assignment operator called" << std::endl;
    if(this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[REQUESTOMY] Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    std::cout << "[EXECUTING...] ";
    if(!this->getIsSigned())
        std::cout << ERR_NOT_SIGNED << std::endl;
    else
    {
        try {
            if(executor.getGrade() > this->getGradeToExecute())
                throw AForm::GradeTooLowException();
            std::cout << "BLIIIIZZ ";
            std::srand(time(NULL)); 
            if(random() % 2 == 0)
                std::cout << this->_target << " has been robotomized successfully" << std::endl;
            else 
                std::cout << " Ops! Robotomy failed" << std::endl;
        } catch (GradeTooLowException &e){
            print_exception(e);
        }
    }
}
