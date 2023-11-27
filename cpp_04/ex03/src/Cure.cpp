#include "../includes/Cure.hpp"

Cure::Cure()
{
    //std::cout << "[CURE] Default constructor called" << std::endl;
    this->type = "cure";
}

Cure::Cure(const Cure& other)
{
    //std::cout << "[CURE] Copy constructor called" << std::endl;
    this->type = other.type;
}

Cure::~Cure()
{
    //std::cout << "[CURE] Destructor called" << std::endl;
}

const Cure& Cure::operator=(const Cure& other)
{
    //std::cout << "[CURE] Assignment operator called" << std::endl;
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

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    //std::cout << "[CURE] Cloning.. " << std::endl;
    return (new Cure(*this));
}