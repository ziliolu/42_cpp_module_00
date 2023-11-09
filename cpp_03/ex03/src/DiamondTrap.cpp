#include "../includes/DiamondTrap.hpp"
#include "../includes/Colors.hpp"


DiamondTrap::DiamondTrap()
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Default constructor called" RESET<< std::endl;
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 50;
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Name constructor called: DiamondTrap is created as " << name << RESET << std::endl;
    ClapTrap(name + "_clap_name");
    this->_name = name;
    this->_hitPoints = 100;
    this->_attackDamage = 30;
    this->_energyPoints = 50;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << PURPLE "[SUB CLASS DIAMOND] Destructor called: DiamondTrap " << this->_name << " is destroyed" RESET << std::endl;

};