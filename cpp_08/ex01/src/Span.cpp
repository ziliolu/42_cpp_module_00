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

int Span::shortestSpan()
{
    if(_vector.size() == 0 || _vector.size() == 1)
        throw(std::out_of_range("Span min can't be found")); 
    
    std::vector<int>::iterator it = _vector.begin();
    int min =  _vector[0];
    for(; it != _vector.end(); ++it)
    {
        if(*it < min)
            min = *it;
    }
    return (min);
}

int Span::longestSpan()
{
    if(_vector.size() == 0 || _vector.size() == 1)
        throw(std::out_of_range("Span max can't be found")); 
    
    std::vector<int>::iterator it = _vector.begin();
    int max =  _vector[0];
    for(; it != _vector.end(); ++it)
    {
        if(*it > max)
            max = *it;
    }
    return (max);
}

void Span::printNumbers()
{
    std::cout << "=== Printing vector ===" << std::endl;
    for(unsigned int i = 0; i < _vector.size(); i++)
        std::cout << "[" << i << "] " <<  _vector[i] << std::endl;
}