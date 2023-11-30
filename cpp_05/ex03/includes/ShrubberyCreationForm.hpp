//
// Created by lpicoli- on 11/29/23.
//

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    
    private:
        std::string _target;

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(ShrubberyCreationForm &src);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};


#endif //SHRUBBERYCREATIONFORM_H
