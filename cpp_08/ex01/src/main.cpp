
#include "../includes/Span.hpp"

int main()
{
    int n = 5;
    Span span(n);

    try
    {
        std::cout << std::endl << "== Test: accessing shortest and longest span in an empty vector ==" << std::endl;
        span.shortestSpan();
        span.longestSpan();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl << std::endl;
    }
    
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
            std::cout << "Error: [" << i * 100 << "] not added to the vector. Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl << "Longest span: " << span.longestSpan() << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << std::endl;

    Span span2(span);
    Span span3;

    span3 = span2;
    span.printNumbers();
    span2.printNumbers();
    span3.printNumbers();
}