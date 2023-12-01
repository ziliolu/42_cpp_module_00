//
// Created by lpicoli- on 11/29/23.
//

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5), _target(target)
{
    std::cout << "[PRESIDENTIAL] Target constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
    std::cout << "[PRESIDENTIAL] Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "[PRESIDENTIAL] Assignment operator called" << std::endl;
    if(this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[PRESIDENTIAL] Destructor called" << std::endl;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    std::cout << "[EXECUTING...] ";
    if(!this->getIsSigned())
    {
        std::cout << ERR_NOT_SIGNED << std::endl;
        return false;
    }
    else
    {
        try {
            if(executor.getGrade() > this->getGradeToExecute())
                throw AForm::GradeTooLowException();
            std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
        } catch (GradeTooLowException &e){
            print_exception(e);
            return false;
        }
    }
    return true;
}
