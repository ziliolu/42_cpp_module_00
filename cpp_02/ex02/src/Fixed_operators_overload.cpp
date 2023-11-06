#include "../includes/Fixed.hpp"

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        _value = other._value;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& object)
{
    os << object.toFloat();
    return (os);
}

// arithmetic operators (+ - * /)

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

// prefixes and postfixes (++i --i i++ i--)

Fixed Fixed::operator++(int) // i++
{
    Fixed tmp = *this;
    ++this->_value;
    return tmp;
}

Fixed Fixed::operator--(int) // i--
{
    Fixed tmp = *this;
    --this->_value;
    return tmp;
}

Fixed& Fixed::operator++() // ++i
{
    ++this->_value;
    return *this;
}
 
Fixed& Fixed::operator--() //--i
{
    --this->_value;
    return *this;
}

// comparision operators (>, <, >=, <=, ==, !=)

bool Fixed::operator>(const Fixed& other)
{
    if(this->toFloat() > other.toFloat())
        return (true);
    return (false); 
}

bool Fixed::operator<(const Fixed& other)
{
    if(this->toFloat() < other.toFloat())
        return (true);
    return (false); 
}

bool Fixed::operator>=(const Fixed& other)
{
    if(this->toFloat() >= other.toFloat())
        return (true);
    return (false); 
}

bool Fixed::operator<=(const Fixed& other)
{
    if(this->toFloat() <= other.toFloat())
        return (true);
    return (false); 
}

bool Fixed::operator!=(const Fixed& other)
{
    if(this->toFloat() != other.toFloat())
        return (true);
    return (false); 
}

bool Fixed::operator==(const Fixed& other)
{
    if(this->toFloat() == other.toFloat())
        return (true);
    return (false); 
}

// min & max
const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
    if(n1.toFloat() > n2.toFloat())
        return (n1);
    return (n2);
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
    if(n1.toFloat() < n2.toFloat())
        return (n1);
    return (n2);
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
    if(n1.toFloat() > n2.toFloat())
        return (n1);
    return (n2);
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
    if(n1.toFloat() < n2.toFloat())
        return (n1);
    return (n2);
}
