#include "../includes/FragTrap.hpp"
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/Colors.hpp"
#include "../includes/DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Jack");
    diamond.displayInfo();
    diamond.attack("John");
};
