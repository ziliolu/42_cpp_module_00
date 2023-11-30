#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

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


        /* ------------ Exception classes ------------*/
        class GradeTooHighException : public std::exception 
        {
            public:
                const char *what() const throw(){
                    return ("Grade out of range: highest value is 1");
                }
        };
        class GradeTooLowException : public std::exception 
        {
            public:
                const char *what() const throw(){
                    return ("Grade out of range: lowest value is 150");
                };
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &object);
#endif