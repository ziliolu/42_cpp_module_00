#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int _value;
        int age;
        static const int _rawBits = 8;
    public:
        Fixed();
        Fixed(const int int_nbr);
        Fixed(const float float_nbr);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
        friend std::ostream& operator<<(std::ostream& os, const Fixed& object);

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed operator++(int);
        Fixed operator--(int);
        Fixed& operator++();
        Fixed& operator--();

        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);
        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);

        static const Fixed& min(const Fixed& n1, const Fixed& n2);
        static const Fixed& max(const Fixed& n1, const Fixed& n2);
        static Fixed& min(Fixed& n1, Fixed& n2);
        static Fixed& max(Fixed& n1, Fixed& n2);
};

#endif