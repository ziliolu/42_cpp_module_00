
#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/Colors.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() 
{
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 100;
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

// Getters
std::string FragTrap::get_name() const
{
    return (this->_name);
}

int FragTrap::get_hitPoints() const
{
    return (this->_hitPoints);
}

int FragTrap::get_energyPoints() const
{
    return (this->_energyPoints);
}

int FragTrap::get_attackDamage() const
{
    std::cout << "calling attck damage" << std::endl;
    return (this->_attackDamage);
}

//Setters
void FragTrap::set_name(std::string name)
{
    this->_name = name;
}
void FragTrap::set_hitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}
void FragTrap::set_energyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}
void FragTrap::set_attackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}