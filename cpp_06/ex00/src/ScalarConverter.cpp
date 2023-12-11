//
// Created by lpicoli- on 12/1/23.
//

#include "../includes/ScalarConverter.hpp"
#include <iostream> 
#include <string>
#include <cstdlib> 
#include <limits>
#include <cmath>

/* Orthodox Canonical Form ------------------------------------------------*/

ScalarConverter::ScalarConverter(){};

ScalarConverter::~ScalarConverter(){};

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    (void)src;
};

ScalarConverter& ScalarConverter:: operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
};
/*--------------------------------------------------------------------------*/

bool error(std::string msg)
{
    std::cout << "Error: " << msg << std::endl;
    return false;
}

bool is_non_displayable(char c)
{
    if(c < 32 || c > 126)
        return true;
    return false;
}

bool isDigit(char c)
{
    if (c < '0' || c > '9')   
        return false;
    return true;
}

bool isValidNum(std::string str, char exception1, char exception2)
{
    int count1 = 0;
    for (int i = 0; i < static_cast<int>(str.size()); i++)
    {
        if(i == 0 && str[i] == '-')
            continue ;
        if(str[i] == exception1)
        {
            int exception1_pos = str.find(exception1);
            if(exception1_pos == 0 || !str.find(exception1))
                return false;
            if(++count1 > 1)
                return false;
        }
        else if(str[i] == exception2)
        {
            int exception2_pos = str.find(exception2);
            if((count1 == 0) || exception2_pos != static_cast<int>(str.size() - 1))
                return false; 
        }
        else if((!isDigit(str[i]) && (str[i] != exception1 || str[i] != exception2)) || is_non_displayable(str[i]))
            return false;
    }
    return true;
}

bool isChar(std::string str)
{
    if(str.size() != 1)
        return false;
    if(isDigit(str[0]) || is_non_displayable(str[0]))
        return false;
    return true;
} 

void toChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void toNum(long double c)
{
    std::cout << "char: ";
    if(c < std::numeric_limits<char>::min() || c > std::numeric_limits<char>::max() || is_non_displayable(c))
        std::cout << "Non displayable" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(c) << "'" << std::endl;

    std::cout << "int: ";
    if(c < -std::numeric_limits<int>::min()|| c > std::numeric_limits<int>::max())
        std::cout << "Overflow" << std::endl;
    else
        std::cout << static_cast<int>(c) << std::endl;

    std::cout << "float: ";
    if(c < -std::numeric_limits<float>::max() || c > std::numeric_limits<float>::max())
        std::cout << "Overflow" << std::endl;
    else if ((c - (int)c) == 0)
        std::cout << static_cast<float>(c) << ".0f" << std::endl;
    else 
        std::cout << static_cast<float>(c) << "f" << std::endl;
    
    std::cout << "double: ";
    if(c < -std::numeric_limits<double>::max() || c > std::numeric_limits<double>::max())
        std::cout << "Overflow" << std::endl;
    else if((c - (int)c) == 0)
         std::cout << static_cast<double>(c) << ".0" << std::endl;
    else 
         std::cout << static_cast<double>(c) << std::endl;
}

bool isPseudoLiteral(std::string str)
{
    if(str == "-inf" || str == "+inf" || str == "-inff" || \
    str == "+inff" || str == "nan")
        return true;
    return false; 
}
void toPseudoLiteral(std::string str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if(str == "-inf" || str == "+inf" || str == "nan")
        std::cout << "float: " << str << "f" << std::endl;
    else
        std::cout << "float: " << str << std::endl;

    if(str == "-inff")
        std::cout << "double: -inf" << std::endl;
    else if(str == "+inff")
        std::cout << "double: +inf" << std::endl;
    else 
        std::cout << "double: " << str << std::endl; 
}

void ScalarConverter::convert(std::string str)
{
    if (isValidNum(str, '\0', '\0') || isValidNum(str, '.', '\0') || isValidNum(str, '.', 'f')) //int, float and double and float
        toNum(std::strtold(str.c_str(), NULL));
    else if(isChar(str))
        toChar(str[0]);
    else if(isPseudoLiteral(str))
        toPseudoLiteral(str);
    else
        std::cout << "Error: invalid argument" << std::endl;
}
