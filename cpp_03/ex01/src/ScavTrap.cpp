
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
     std::cout << "[SUB CLASS] Name constructor called: ScavTrap is created as " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other)
{
    std::cout << "[SUB CLASS] Copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "[SUB CLASS] Destructor called: ScavTrap " << this->_name << " is destroyed" << std::endl;
}

// Member functions
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->get_name() << " is in Gate Keeper Mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "[ ATTACKING... ]";
    if(!_isDead)
    {
        if(this->_energyPoints <= 0)
            std::cout << " Impossible to attack: no more energy points available" << std::endl;
        else
        {
            this->_energyPoints--;
            std::cout << " ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
        }
    }
    checkDeath();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(this != &other)
    {
        std::cout << "[SUB CLASS] Copy assignment operator called" << std::endl;
        this->_name = other._name;
        this->_isDead = other._isDead;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}
