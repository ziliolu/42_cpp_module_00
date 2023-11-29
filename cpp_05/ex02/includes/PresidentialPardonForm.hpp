//
// Created by lpicoli- on 11/29/23.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(PresidentialPardonForm &src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;

};


#endif //PRESIDENTIALPARDONFORM_HPP
