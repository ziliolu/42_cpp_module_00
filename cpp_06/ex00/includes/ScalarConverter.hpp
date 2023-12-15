//
// Created by lpicoli- on 12/1/23.
//

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# define INVALID_ARGS "Invalid number of arguments"

class ScalarConverter {

    /* Orthodox Canonical Form ----------------------------------*/
    private: 
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter &src);
        ScalarConverter& operator=(const ScalarConverter &other);
    /*-----------------------------------------------------------*/
    public:
        static void convert(std::string str);
};

bool error(std::string msg);

#endif //CPPS_GITHUB_SCALARCONVERTER_HPP
 