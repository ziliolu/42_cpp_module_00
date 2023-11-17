#include "../includes/ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "Default constructor called" << std::endl;
}

ICharacter::ICharacter(std::string name)
{
    std::cout << "Name constructor called" << std::endl;
    this->_name = name;
}

ICharacter::ICharacter(const ICharacter& other)
{
    this->_name = other._name;
}

ICharacter::~ICharacter()
{
    std::cout << "Destructor called" << std::endl;
}

const ICharacter& ICharacter::operator=(const ICharacter& other)
{
    if(this != &other)
    {
        this->_name = other._name;
    }
    return (*this);
}

void ICharacter::setName(std::string name)
{
    this->_name = name;
}

std::string ICharacter::getName()
{
    return this->_name;
}