/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:30:47 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/27 16:35:42 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main()
{
    int n = 5;
    Span span(n);

    try
    {   
        Span spanRange(10);
        std::cout << std::endl << GREEN_TEXT << "== Test: filling the vector with a range of random numbers ==" << RESET_COLOR << std::endl;
        spanRange.addNumber(5);
        spanRange.addManyNumbers(9);
        spanRange.printNumbers();
        std::cout << GREEN_TEXT << "[OK]" << RESET_COLOR << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_TEXT << "Exception caught: " << e.what() << RESET_COLOR << std::endl;
        std::cout << RED_TEXT << "[K0]" << RESET_COLOR << std::endl;
    }

    try
    {   
        Span spanRetetiveNumber(10);
        std::cout << std::endl << GREEN_TEXT << "== Test: shortest with repetitive numbers ==" << RESET_COLOR << std::endl;
        spanRetetiveNumber.addNumber(5);
        spanRetetiveNumber.addNumber(5);
        spanRetetiveNumber.addNumber(10);
        spanRetetiveNumber.addNumber(11);
        spanRetetiveNumber.printNumbers();
        std::cout << std::endl << "Longest span: " << spanRetetiveNumber.longestSpan() << std::endl;
        std::cout << "Shortest span: " << spanRetetiveNumber.shortestSpan() << std::endl;
        std::cout << GREEN_TEXT << "[OK]" << RESET_COLOR << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_TEXT << "Exception caught: " << e.what() << RESET_COLOR << std::endl;
        std::cout << RED_TEXT << "[K0]" << RESET_COLOR << std::endl;
    }
    
    try
    {
        std::cout << std::endl << GREEN_TEXT << "== Test: accessing shortest and longest span in an empty vector ==" << RESET_COLOR << std::endl;
        span.shortestSpan();
        span.longestSpan();
        std::cout << GREEN_TEXT << "[OK]" << RESET_COLOR << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED_TEXT << "Exception caught: " << e.what() << RESET_COLOR << std::endl;
        std::cout << RED_TEXT << "[K0]" << RESET_COLOR << std::endl << std::endl;
    }
    
    std::cout << std::endl << GREEN_TEXT << "== Test: manual filling with addNumber() ==" << RESET_COLOR << std::endl;
    std::cout << "=== Filling vector ===" << std::endl;
    for(int i = 0; i <= n; i++)
    {
        try 
        {
            span.addNumber(i * 100);
            std::cout << "[" << i * 100 << "] added to the vector" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << RED_TEXT << "Error: [" << i * 100 << "] not added to the vector. Exception caught: " << e.what() << RESET_COLOR << std::endl;
            std::cout << RED_TEXT << "[K0]" << RESET_COLOR << std::endl;
        }
    }
    std::cout << std::endl << "Longest span: " << span.longestSpan() << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl << GREEN_TEXT << "== Test: copy constructor and overload operator ==" << RESET_COLOR << std::endl;
    Span span2(span);
    Span span3;

    span3 = span2;
    span.printNumbers();
    span2.printNumbers();
    span3.printNumbers();

    try 
    {
        std::cout << std:: endl << GREEN_TEXT << "== Test: adding 10000 numbers to the vector ==" << RESET_COLOR << std::endl;  
        int n = 10000;
        Span span(n);
        for(int i = 0; i < n; i++)
        {
            span.addNumber(i + 1);
        }
        std::cout << "All 10000 numbers added successfully to the vector!" << std::endl;
        std::cout << std::endl << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << RED_TEXT << "Exception caught: " << e.what() << RESET_COLOR << std::endl;
            std::cout << RED_TEXT << "[K0]" << RESET_COLOR << std::endl << std::endl;
    }
}