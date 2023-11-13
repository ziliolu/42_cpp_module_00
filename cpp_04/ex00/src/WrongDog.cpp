#include "../includes/WrongDog.hpp"

WrongDog::WrongDog()
{
    std::cout << "[WrongDog] Default constructor called" << std::endl;
    this->type = "WrongDog";
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
    std::cout << "[WrongDog] Copy constructor called" << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout << "[WrongDog] Destructor called" << std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
    std::cout << "[WrongDog] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

void WrongDog::makeSound() const
{
    std::cout << "[WrongDog] Au au au" << std::endl;
}