#include "../includes/Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

// int main( void ) {

//     Fixed a;
//     Fixed n1(10);
//     Fixed n2(5);
//     std::cout << "--- Initialization ---" << std::endl;
//     std::cout << "n1: " << n1 << std::endl;
//     std::cout << "n2: " << n2 << std::endl;
//     std::cout << "a: " << a << std::endl;

//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     // prefixes and postfixes (++i --i i++ i--)
//     std::cout << std::endl << "--- prefixes and postfixes (++i --i i++ i--) ---" << std::endl;
//     std::cout << "a " << a << std::endl;
//     std::cout << "++a " << ++a << std::endl;
//     std::cout << "a " << a << std::endl;
//     std::cout << "a++ " << a++ << std::endl;
//     std::cout << "a " << a << std::endl;
//     std::cout << "--a " << --a << std::endl;
//     std::cout << "a " << a << std::endl;
//     std::cout << "a-- " << a-- << std::endl;
//     std::cout << "a " << a << std::endl;

//     // arithmetic operators (+ - * /)
//     std::cout << std::endl << "--- arithmetic operators (+ - * /) ---" << std::endl;
//     std::cout << "n1 + n2: " << n1 + n2 << std::endl;
//     std::cout << "n1 - n2: " << n1 - n2 << std::endl;
//     std::cout << "n1 * n2: " << n1 * n2 << std::endl;
//     std::cout << "n1 / n2: " << n1 / n2 << std::endl;
    
//     std::cout << std::endl << "--- comparison operators (>, <, >=, <=, ==, !=) ---" << std::endl;
//     if(n1 > n2)
//         std::cout << "n1 greater than n2" << std::endl;
//     if(n1 >= n2)
//         std::cout << "n1 greater or equal to n2" << std::endl;
//     if(n1 == n2)
//         std::cout << "n1 equal to n2" << std::endl;
//     if(n1 < n2)
//         std::cout << "n1 small than n2" << std::endl;
//     if(n1 <= n2)
//         std::cout << "n1 smaller or equal to n2" << std::endl;
//     if(n1 != n2)
//         std::cout << "n1 different to n2" << std::endl;

//     //max & min (+ - * /)
//     std::cout << std::endl << "--- Max and min ---" << std::endl;
//     std::cout << "Max: " << Fixed::max(n1, n2) << std::endl;
//     std::cout << "Min: " << Fixed::min(n1, n2) << std::endl;
//     return 0;
// }