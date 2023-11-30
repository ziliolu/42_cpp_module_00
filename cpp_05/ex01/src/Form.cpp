//
// Created by lpicoli- on 11/28/23.
//

#include "../includes/Form.hpp"

Form::Form() :_name("Default form's name"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
    std::cout << "[FORM] Default constructor called" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "[FORM] Complete constructor called" << std::endl;
}

Form::Form(Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "[FORM] Copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "[FORM] Destructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    std::cout << "[FORM] Assignment operator called" << std::endl;
    if(this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}

const std::string Form::getName()
{
    return this->_name;
}

bool Form::getIsSigned()
{
    return this->_isSigned;
}

int Form::getGradeToSign()
{
    return this->_gradeToSign;
}

int Form::gradeToExecute()
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    std::cout << "[SIGNING FORM...] ";
    try {
        if(bureaucrat.getGrade() > this->_gradeToSign)
            throw GradeTooLowException();
        else if(bureaucrat.getGrade() <= 0)
            throw GradeTooHighException();
        this->_isSigned = true;
    } catch (GradeTooLowException &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    } catch (GradeTooHighException &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    bureaucrat.signForm(*this);

}

std::ostream& operator<<(std::ostream& os, Form &object) 
{
    if(object.getIsSigned())
        return os << "Form is signed!";
    else 
        return os << "Form is still not signed!";
}

