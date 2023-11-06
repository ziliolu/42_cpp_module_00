#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

    private:
        int _value;
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

        /**
         * a palavra-chave const no final da declaração 
         * indica que essa função é uma função membro constante, 
         * o que significa que ela não pode modificar os 
         * membros de dados da classe em que está definida.
        */
        float toFloat() const;
        int toInt() const;
        friend std::ostream& operator<<(std::ostream& os, const Fixed& object);
};

#endif