#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
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
        int shortestSpan();
        int longestSpan();
        void printNumbers();
        void addManyNumbers(int nNumbers);
};

#endif