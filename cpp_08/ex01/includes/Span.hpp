/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:30:33 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/27 16:14:47 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Colors.hpp"


class Span
{
    private:
        unsigned int N;
        std::vector<int> _vector;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        const Span& operator=(const Span &other);
        ~Span();
        void addNumber(int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void printNumbers();
        void addManyNumbers(int nNumbers);
};

#endif