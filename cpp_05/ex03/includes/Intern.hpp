//
// Created by lpicoli- on 11/28/23.
//

#ifndef INTERN_H
#define INTERN_H

# include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern 
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        AForm *makeForm(std::string formName, std::string target) const;
};

#endif