#include "../includes/ClapTrap.hpp"
#include "../includes/Colors.hpp"

// Member functions 
bool ClapTrap::checkDeath()
{
    if(this->_hitPoints <= 0 && this->_energyPoints <= 0)
    {
        std::cout << " Ops! ClapTrap is dead" << std::endl;
        this->_isDead = true;
        return (true);
    }
    return (false);
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << YELLOW "[ ATTACKING... ]";
    if(!_isDead)
    {
        if(this->_energyPoints <= 0)
            std::cout << " Impossible to attack: no more energy points available" RESET << std::endl;
        else
        {
            this->_energyPoints--;
            std::cout << " ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" RESET << std::endl;
        }
    }
    checkDeath();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << YELLOW "[ TAKING DAMAGE... ]";
    if(!_isDead)
    {
        std::cout << " ClapTrap " << this->_name << " was attacked and lost " << amount << " hit points " RESET << std::endl;
        this->_hitPoints -= amount;
    }
    checkDeath();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << YELLOW "[ REPAIRING... ]";
    if(!_isDead)
    {
        if(this->_energyPoints <= 0)
            std::cout << " Impossible to repair: no more energy points available" RESET << std::endl;
        else 
        {
            this->_energyPoints--;
            this->_hitPoints += amount;
            std::cout << " ClapTrap " << this->_name << " is repaired and received " << amount << " of hit points" RESET << std::endl;
        }
    }
    checkDeath();
}

void ClapTrap::displayInfo()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "[ NAME ] [ " << _name << " ]" << std::endl;
    std::cout << "[ HIT POINTS ] [ " << _hitPoints << " ]" << std::endl;
    std::cout << "[ ENERGY POINTS ] [ " << _energyPoints << " ]" << std::endl;
    std::cout << "[ ATTACK DAMAGE ] [ " << _attackDamage << " ]" << std::endl;
    std::cout << "----------------------" << std::endl;
}

// Default constructor 
ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0), _isDead(false)
{
    std::cout << YELLOW "[SUPER CLASS] Default constructor called" RESET << std::endl;
}

// Name constructor
ClapTrap::ClapTrap(std::string name)
{
    std::cout << YELLOW "[SUPER CLASS] Name constructor called: ClapTrap is created"RESET << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    this->_isDead = false;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << YELLOW "[SUPER CLASS] Copy constructor called" RESET << std::endl;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    this->_isDead = other._isDead;
}

// Destructor 
ClapTrap::~ClapTrap()
{
    std::cout << YELLOW "[SUPER CLASS] Destructor called: ClapTrap is destroyed" RESET << std::endl;
}

// Operator overload 
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        std::cout << YELLOW "[SUPER CLASS] Copy assignment operator called" RESET << std::endl;
        this->_name = other._name;
        this->_isDead = other._isDead;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

// Getters
std::string ClapTrap::get_name() const
{
    return (this->_name);
}

int ClapTrap::get_hitPoints() const
{
    return (this->_hitPoints);
}

int ClapTrap::get_energyPoints() const
{
    return (this->_energyPoints);
}

int ClapTrap::get_attackDamage() const
{
    return (this->_attackDamage);
}

//Setters
void ClapTrap::set_name(std::string name)
{
    this->_name = name;
}
void ClapTrap::set_hitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
}
void ClapTrap::set_energyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}
void ClapTrap::set_attackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}