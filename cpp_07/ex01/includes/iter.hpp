#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *arr, size_t length, void (*func)(T&))
{
    for(size_t i = 0; i < length; i++)
        func(arr[i]);
}

template <typename T>
void ft_print(T value)
{
    std::cout << value << std::endl;
}

template <typename T>
void ft_increment(T &value)
{
    value++;
}

#endif