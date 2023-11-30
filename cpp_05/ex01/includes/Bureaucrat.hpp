#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
# include "Form.hpp"


class Form;

class Bureaucrat 
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        void incrementGrade(int value);
        void decrementGrade(int value);

        const std::string &getName() const;
        int getGrade() const;
        void signForm(Form &form);
        /* ------------ Exception classes ------------*/
        class GradeTooHighException : public std::exception 
        {
            public:
                const char *what() const throw(){
                    return ("Grade too high");
                }
        };
        class GradeTooLowException : public std::exception 
        {
            public:
                const char *what() const throw(){
                    return ("Grade too low");
                };
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &object);

#endif