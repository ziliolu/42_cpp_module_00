#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>

int main()
{
    Base *base_ptr;
    base_ptr = generate();

    std::cout << "--- Identifying ptr ---" << std::endl; 
    identify(base_ptr);

    std::cout << std::endl << "--- Identifying reference ---" << std::endl; 
    Base& ref_base = *base_ptr;
    identify(ref_base);
}