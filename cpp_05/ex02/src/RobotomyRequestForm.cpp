//
// Created by lpicoli- on 11/29/23.
//

#include "../includes/RobotomyRequestForm.hpp"

//
// Created by lpicoli- on 11/29/23.
//

#include "../includes/RobotomyRequestForm.hpp"

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
            static int i;
            std::cout << i << std::endl;
            if(i % 2 == 0)
                std::cout << "BLIIIIZZ " << this->_target << " has been robotomized successfully" << std::endl;
            else 
                std::cout << "Ops! Robotomy failed";
        } catch (GradeTooLowException &e){
            print_exception(e);
        }
    }
}
