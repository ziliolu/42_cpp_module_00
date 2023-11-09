
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
     std::cout << GREEN "[SUB CLASS FRAGTRAP] Name constructor called: FragTrap is created as " << name << RESET << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << GREEN "[SUB CLASS FRAGTRAP] Destructor called: FragTrap " << this->_name << " is destroyed" RESET << std::endl;
}

// Member functions
void FragTrap::highFivesGuys()
{
    std::cout << GREEN "[SUB CLASS FRAGTRAP] FragTrap " << this->get_name() << " gives you a high five 👋" RESET << std::endl;
}