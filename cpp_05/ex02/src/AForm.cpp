//
// Created by lpicoli- on 11/28/23.
//

#include "../includes/AForm.hpp"

void print_exception(std::exception &e)
{
    std::cout << "Exception caught: " << e.what() << std::endl;
}

AForm::AForm() :_name("Default Aform's name"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
    std::cout << "[AFORM] Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "[AFORM] Complete constructor called" << std::endl;
}

AForm::AForm(AForm &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "[AFORM] Copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "[AFORM] Destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    std::cout << "[AFORM] Assignment operator called" << std::endl;
    if(this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

const std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const 
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    std::cout << "[SIGNING FORM...] ";
    try {
        if(bureaucrat.getGrade() > this->_gradeToSign)
            throw GradeTooLowException();
        else if(bureaucrat.getGrade() <= 0)
            throw GradeTooHighException();
        this->_isSigned = true;
    } catch (GradeTooLowException &e){
        print_exception(e);
    } catch (GradeTooHighException &e){
        print_exception(e);
    }
    bureaucrat.signForm(*this);

}


