#include "../includes/Dog.hpp"

Dog::Dog()
{
    std::cout << "[Dog] Default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Au au au" << std::endl;
}