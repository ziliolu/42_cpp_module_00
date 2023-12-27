/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:30:59 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/27 16:30:24 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &src)
{
    std::cout << "[Copy constructor called]" << std::endl;
    N = src.N;
    _vector = src._vector;
}
const Span& Span::operator=(const Span &other)
{
    std::cout << "[Copy assignment operator called]" << std::endl;
    if(this != &other)
    {
        N = other.N;
        _vector = other._vector;
    }
    return (*this);
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if(_vector.size() >= N)
        throw( std::out_of_range("limit of numbers reached"));
    _vector.push_back(number);
}

void Span::addManyNumbers(int nNumbers)
{
    std::srand(std::time(NULL));
    for(int i = _vector.size(); i <= nNumbers; i++)
    {
        if(_vector.size() >= N)
            throw( std::out_of_range("limit of numbers reached"));
        _vector.push_back(rand());
    }
}

unsigned int Span::shortestSpan()
{
    if(_vector.size() == 0 || _vector.size() == 1)
        throw(std::out_of_range("Span min can't be found"));
        
    std::sort(_vector.begin(), _vector.end());
    unsigned int minDifference = _vector[1] - _vector[0];
    for(unsigned int i = 2; i < _vector.size(); i++)
    {
        unsigned int currentDifference = _vector[i] - _vector[i - 1];
        if(currentDifference < minDifference)
            minDifference = currentDifference;
    }
    return (minDifference);
}

unsigned int Span::longestSpan()
{
    if(_vector.size() == 0 || _vector.size() == 1)
        throw(std::out_of_range("Span min can't be found")); 

    std::sort(_vector.begin(), _vector.end());
    unsigned int min = _vector.front();
    unsigned int max = _vector.back();

    return (max - min);
}

void Span::printNumbers()
{
    std::cout << "=== Printing vector ===" << std::endl;
    for(unsigned int i = 0; i < _vector.size(); i++)
        std::cout << "[" << i << "] " <<  _vector[i] << std::endl;
}