#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria()
{
    //std::cout << "[AMATERIA] Default constructor called" << std::endl;
    this->type = "";
}

AMateria::AMateria(std::string const& type)
{
    this->type = type;
}
AMateria::AMateria(const AMateria& other)
{
    (void)other;
}

AMateria::~AMateria()
{
    //std::cout << "[AMATERIA] Destructor called" << std::endl;
}

const AMateria& AMateria::operator=(const AMateria& other)
{
    (void) other;
    return (*this);
}

std::string const& AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{   
    (void) target;
    //std::cout << "AMateria used on " << target.getName() << std::endl; 
}