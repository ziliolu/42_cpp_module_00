//
// Created by lpicoli- on 12/1/23.
//

#include <iostream>

template  <typename T>
T max(T arg1, T arg2)
{
    if(arg1 > arg2)
        return arg1;
    return arg2;
}

template  <typename T>
T min(T arg1, T arg2)
{
    if(arg1 < arg2)
        return arg1;
    return arg2;
}

int main()
{
    std::cout << max("a", "b") << std::endl;
}