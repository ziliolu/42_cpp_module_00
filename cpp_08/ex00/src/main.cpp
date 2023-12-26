/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:51:19 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/26 13:59:10 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include "../includes/Colors.hpp"

int main()
{
    try 
    {
        std::vector<int> int_arr;
        int_arr.push_back(1);
        int_arr.push_back(5);
        int_arr.push_back(10);    
        easyfind(int_arr, 10);
    } 
    catch(std::exception &e)
    {
        std::cout << RED_TEXT << "Exception caught: " << e.what() << RESET_COLOR << std::endl;
    }
}