
#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/Colors.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() 
{
    std::cout << GREEN "[SUB CLASS FRAGTRAP] Default constructor called" RESET<< std::endl;
}

// Name constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 100;
     std::cout << GREEN "[SUB CLASS FRAGTRAP] Name constructor called: FragTrap is created" RESET << std::endl;
}

// Copy constructor 
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "[SUB CLASS FRAGTRAP] Copy constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << GREEN "[SUB CLASS FRAGTRAP] Destructor called: FragTrap is destroyed" RESET << std::endl;
}

// Member functions
void FragTrap::highFivesGuys()
{
    std::cout << GREEN "[SUB CLASS FRAGTRAP] FragTrap gives you a high five 👋" RESET << std::endl;
}

// Overload operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if(this != &other)
    {
        std::cout << GREEN "[SUB CLASS FRAGTRAP] Copy assignment operator called" RESET << std::endl;
        this->_name = other._name;
        this->_isDead = other._isDead;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}