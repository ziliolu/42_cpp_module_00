#include "../includes/Animal.hpp"

Animal::Animal()
{
    std::cout << "[Animal] Default constructor called" << std::endl;
    this->type = "";
}

Animal::Animal(std::string type)
{
    std::cout << "[Animal] Type constructor called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal& other)
{
    std::cout << "[Animal] Copy constructor called" << std::endl;
    this->type = other.type;
}

Animal::~Animal()
{
    std::cout << "[Animal] Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "[Animal] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "[Animal] Making default sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
} 
