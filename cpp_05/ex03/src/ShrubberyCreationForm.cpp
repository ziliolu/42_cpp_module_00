//
// Created by lpicoli- on 11/29/23.
//

#include <fstream>
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), _target(target)
{
    std::cout << "[SHRUBBERY] Target constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
    std::cout << "[SHRUBBERY] Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "[SHRUBBERY] Assignment operator called" << std::endl;
    if(this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[SHRUBBERY] Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::cout << "[EXECUTING...] ";
    if(!this->getIsSigned())
        std::cout << ERR_NOT_SIGNED << std::endl;
    else
    {
        try {
            if(executor.getGrade() > this->getGradeToExecute())
                throw AForm::GradeTooLowException();
            std::ofstream outFile;
            std::string outFileName = this->_target + "_shrubbery";
            outFile.open(outFileName.c_str(), std::ofstream::in | std::ofstream::trunc);
            if(outFile.is_open())
            {
                std::cout << outFileName << " successfully created!" << std::endl;
               outFile  << std::endl
			            << "                                            ." << std::endl
			            << "                                    .         ;  " << std::endl
			            << "       .              .              ;%     ;;   " << std::endl
                        << "         ,           ,                :;%  %;   " << std::endl
                        << "          :         ;                   :;%;'     .,   " << std::endl
                        << " ,.        %;     %;            ;        %;'    ,;" << std::endl
                        << "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
                        << "    %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl
                        << "     ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
                        << "      `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
                        << "       `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
                        << "          `:%;.  :;bd%;          %;@%;'" << std::endl
                        << "            `@%:.  :;%.         ;@@%;'   " << std::endl
                        << "              `@%.  `;@%.      ;@@%;         " << std::endl
                        << "                `@%%. `@%%    ;@@%;        " << std::endl
                        << "                  ;@%. :@%%  %@@%;       " << std::endl
                        << "                    %@bd%%%bd%%:;     " << std::endl
                        << "                      #@%%%%%:;;" << std::endl
                        << "                      %@@%%%::;" << std::endl
                        << "                      %@@@%(o);  . '         " << std::endl
                        << "                      %@@@o%;:(.,'         " << std::endl
                        << "                  `.. %@@@o%::;         " << std::endl
                        << "                     `)@@@o%::;         " << std::endl
                        << "                      %@@(o)::;        " << std::endl
                        << "                     .%@@@@%::;         " << std::endl
                        << "                     ;%@@@@%::;.          " << std::endl
                        << "                    ;%@@@@%%:;;;. " << std::endl
                        << "                ...;%@@@@@%%:;;;;,..   " << std::endl;
                        outFile.close();
		    }
            } catch (GradeTooLowException &e){
                print_exception(e);
            }
    }
}