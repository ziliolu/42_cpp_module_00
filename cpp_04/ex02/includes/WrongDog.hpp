#ifndef WRONG_DOG_HPP
# define WRONG_DOG_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongDog : public WrongAnimal
{
    public:
        WrongDog();
        WrongDog(const WrongDog& other);
        ~WrongDog();
        WrongDog& operator=(const WrongDog& other);
        void makeSound() const;
};

#endif
