#include "../includes/DiamondTrap.hpp"
#include "../includes/Colors.hpp"


DiamondTrap::DiamondTrap()
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Default constructor called" RESET<< std::endl;
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Name constructor called: DiamondTrap is created" RESET << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Copy constructor called" RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if(this != &other)
    {
        std::cout << PURPLE "[SUB CLASS DIAMOND] Copy assignment operator called" RESET << std::endl;
        this->_name = other._name;
        ClapTrap::_name = (this->_name + "_clap_name");
        this->_isDead = other._isDead;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Destructor called: DiamondTrap is destroyed" RESET << std::endl;

};

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name: " << this->_name << std::endl;
    std::cout << "ClapTrap's name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::displayInfo()
{
    std::cout << "----------------------" << std::endl;
    std::cout << "[ NAME ] [ " << _name << " ]" << std::endl;
    std::cout << "[ HIT POINTS ] [ " << _hitPoints << " ]" << std::endl;
    std::cout << "[ ENERGY POINTS ] [ " << _energyPoints << " ]" << std::endl;
    std::cout << "[ ATTACK DAMAGE ] [ " << _attackDamage << " ]" << std::endl;
    std::cout << "----------------------" << std::endl;
}