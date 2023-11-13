#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[WrongAnimal] Default constructor called" << std::endl;
    this->type = "";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "[WrongAnimal] Type constructor called" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "[WrongAnimal] Copy constructor called" << std::endl;
    this->type = other.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "[WrongAnimal] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] Making default sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
} 
