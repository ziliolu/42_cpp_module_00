#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat's name"), _grade(0)
{
    std::cout << "[BUREAUCRAT] Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string name, int grade) :_name(name), _grade(grade)
{
    std::cout << "[BUREAUCRAT] Name + Grade constructor called" << std::endl;
    try {
        if(grade > 150)
            throw GradeTooLowException();
        else if (grade <= 0)
            throw GradeTooHighException();
    } catch (Bureaucrat::GradeTooLowException &e) {
        print_exception(e);
    } catch (Bureaucrat::GradeTooHighException &e) {
        print_exception(e);
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade())
{
    std::cout << "[BUREAUCRAT] Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "[BUREAUCRAT] Assignment operator called" << std::endl;
    if(this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &object)
{
    return os << object.getName() << ", bureaucrat grade " << object.getGrade();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[BUREAUCRAT] Destructor called" << std::endl;
}

void Bureaucrat::incrementGrade(int value)
{
    std::cout << "[BUREAUCRAT] Incrementing grade..." << std::endl;
    std::cout << "Grade before = " << this->_grade << std::endl;
    std::cout << "Value to increment = " << value << std::endl;
    try 
    {
        if(_grade - value <= 0)
            throw GradeTooHighException();
        _grade -= value;
        std::cout << "Grade after = " << this->_grade << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e){
        print_exception(e);
    }
}

void Bureaucrat::decrementGrade(int value)
{
    std::cout << "[BUREAUCRAT] Decrementing grade..." << std::endl;
    std::cout << "Grade before = " << this->_grade << std::endl;
    std::cout << "Value to decrement = " << value << std::endl;
    try {
        if(_grade + value > 150)
            throw GradeTooLowException();
        _grade += value;
        std::cout << "Grade after = " << this->_grade << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e){
        print_exception(e);
    }
}

const std::string & Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::signForm(AForm &form)
{   
    if(form.getIsSigned())
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because the grade is too ";
        if(this->_grade > form.getGradeToSign())
            std::cout << "low" << std::endl;
        else
            std::cout << "high" << std::endl;
    }
}
