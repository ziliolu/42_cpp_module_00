
#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() 
{
    std::cout << "[SUB CLASS] Default constructor called" << std::endl;
}

// Name constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
     std::cout << "[SUB CLASS] Name constructor called: ClapTrap is created as " << name << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "[SUB CLASS] Destructor called: ClapTrap " << this->_name << " is destroyed" << std::endl;
}

// Member functions
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->get_name() << " is in Gate Keeper Mode!" << std::endl;
}