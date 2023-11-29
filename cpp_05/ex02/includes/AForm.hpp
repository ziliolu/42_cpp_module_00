//
// Created by lpicoli- on 11/28/23.
//

#ifndef AFORM_H
#define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"
# define ERR_NOT_SIGNED "Error: form still not signed"

void print_exception(std::exception &e);
class Bureaucrat;

class AForm {

    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm &src);
        AForm& operator=(const AForm &other);
        ~AForm();
        friend std::ostream operator<<(std::ostream os, AForm &object);

        /* Getters */
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        
        int getGradeToExecute() const;
        void beSigned(Bureaucrat &bureaucrat);
        
        virtual void execute(Bureaucrat const & executor) const = 0;
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

#endif //AFORM_H
