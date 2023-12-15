//
// Created by lpicoli- on 12/1/23.
//

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
        return error("Invalid number of arguments");
    
    std::string str = argv[1];
    ScalarConverter::convert(str);
}
