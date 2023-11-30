//
// Created by lpicoli- on 11/29/23.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(RobotomyRequestForm &src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
