//
// Created by lpicoli- on 12/1/23.
//

#include <iostream>
#include "../includes/iter.hpp"

int main()
{
    int arr_int[3] = {1, 2, 3};
    double arr_double[3] = {1.5, 2.5, 3.5};
    std::string arr_str[4] = {"first", "second", "third", "forth"};

    /* Int array test */
    std::cout << std::endl << "Int Array Test" << std::endl;
    ::iter(arr_int, 3, ::ft_print);
    std::cout << "Incrementing numbers.." << std::endl;
    ::iter(arr_int, 3, ::ft_increment);
    ::iter(arr_int, 3, ::ft_print);

    /* Double array test */
    std::cout << std::endl << "Double Array Test" << std::endl;
    ::iter(arr_double, 3, ::ft_print);
    std::cout << "Incrementing numbers.." << std::endl;
    ::iter(arr_double, 3, ::ft_increment);
    ::iter(arr_double, 3, ::ft_print);

    /* Double array test */
    std::cout << std::endl << "String Array Test" << std::endl;
    ::iter(arr_str, 4, ::ft_print);
}