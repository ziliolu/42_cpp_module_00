#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed& other)
{
    //std::cout << "Copy constructor called" << std::endl;
    _value = other._value;
}

Fixed::Fixed(const int int_nbr) : _value(int_nbr << _rawBits)
{
    //std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float float_nbr) : _value(roundf(float_nbr * (1 << _rawBits)))
{
    //std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const value)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = value;
}


float Fixed::toFloat() const
{
    float f = (static_cast<float> (_value)) / (1 << _rawBits);
    return (f);
}

int Fixed::toInt() const
{
    return (_value >> _rawBits);
}