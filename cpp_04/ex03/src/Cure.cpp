#include "../includes/Cure.hpp"

Cure::Cure()
{
    std::cout << "Default constructor called" << std::endl;
    this->type = "cure";
}

Cure::Cure(const Cure& other)
{
    this->type = other.type;
}

Cure::~Cure()
{
    std::cout << "Destructor called" << std::endl;
}

const Cure& Cure::operator=(const Cure& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string const& Cure::getType() const 
{
    return type;
}