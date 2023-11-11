#include "../includes/ScavTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/Colors.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() 
{
    std::cout << CYAN "[SUB CLASS SCAVTRAP] Default constructor called" RESET << std::endl;
}

// Name constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_attackDamage = 20;
    this->_energyPoints = 50;
     std::cout << CYAN "[SUB CLASS SCAVTRAP] Name constructor called: ScavTrap is created" RESET << std::endl;
}

// Copy operator
ScavTrap::ScavTrap(const ScavTrap& other) :ClapTrap(other)
{
    std::cout << CYAN "[SUB CLASS SCAVTRAP] Copy constructor called" RESET << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << CYAN "[SUB CLASS SCAVTRAP] Destructor called: ScavTrap is destroyed" RESET << std::endl;
}

// Member functions
void ScavTrap::guardGate()
{
    std::cout << CYAN "ScavTrap is in Gate Keeper Mode!" RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << CYAN "[ ATTACKING... ]";
    if(!_isDead)
    {
        if(this->_energyPoints <= 0)
            std::cout << " Impossible to attack: no more energy points available" RESET << std::endl;
        else
        {
            this->_energyPoints--;
            std::cout << " ScavTrap attacks " << target << " causing " << this->_attackDamage << " points of damage!" RESET << std::endl;
        }
    }
    checkDeath();
}

// Overload operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if(this != &other)
    {
        std::cout << CYAN "[SUB CLASS SCAVTRAP] Copy assignment operator called" RESET << std::endl;
        this->_name = other._name;
        this->_isDead = other._isDead;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}