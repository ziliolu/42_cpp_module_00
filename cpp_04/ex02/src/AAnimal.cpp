#include "../includes/AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "[AAnimal] Default constructor called" << std::endl;
    this->type = "";
}

AAnimal::AAnimal(std::string type)
{
    std::cout << "[AAnimal] Type constructor called" << std::endl;
    this->type = type;
}

AAnimal::AAnimal(const AAnimal& other)
{
    std::cout << "[AAnimal] Copy constructor called" << std::endl;
    this->type = other.type;
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] Destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << "[AAnimal] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

std::string AAnimal::getType() const
{
    return this->type;
} 
