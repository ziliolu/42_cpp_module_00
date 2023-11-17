#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default constructor called" << std::endl;
    this->type = "";
}

AMateria::AMateria(const AMateria& other)
{
    this->type = other.type;
}

AMateria::~AMateria()
{
    std::cout << "Destructor called" << std::endl;
}

const AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string const& AMateria::getType() const
{
    return this->type;
}
