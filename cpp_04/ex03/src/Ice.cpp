#include "../includes/Ice.hpp"

Ice::Ice()
{
    std::cout << "Default constructor called" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice& other)
{
    this->type = other.type;
}

Ice::~Ice()
{
    std::cout << "Destructor called" << std::endl;
}

const Ice& Ice::operator=(const Ice& other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string const& Ice::getType() const 
{
    return type;
}