//
// Created by lpicoli- on 11/28/23.
//

#ifndef FORM_H
#define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form &src);
        Form& operator=(const Form &other);
        ~Form();
        friend std::ostream operator<<(std::ostream os, Form &object);

        /* Getters */
        const std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int gradeToExecute();

        void beSigned(Bureaucrat &bureaucrat);
        /* ------------ Exception classes ------------*/
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw(){
                    return ("Grade too high");
                };
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw(){
                    return ("Grade too low");
                };
        };
};

#endif //FORM_H
