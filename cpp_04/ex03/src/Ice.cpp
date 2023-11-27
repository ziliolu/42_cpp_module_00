#include "../includes/Ice.hpp"

Ice::Ice()
{
    //std::cout << "[ICE] Default constructor called" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice& other)
{
    //std::cout << "[ICE] Copy constructor called" << std::endl;
    this->type = other.type;
}

Ice::~Ice()
{
    //std::cout << "[ICE] Destructor called" << std::endl;
}

const Ice& Ice::operator=(const Ice& other)
{
    //std::cout << "[ICE] Assignment operator called" << std::endl;
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

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    //std::cout << "[ICE] Cloning.. " << std::endl;
    return (new Ice(*this));
}