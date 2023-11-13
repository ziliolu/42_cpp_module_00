#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] Miaaaaau" << std::endl;
}