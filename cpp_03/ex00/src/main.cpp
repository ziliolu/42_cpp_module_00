#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap c1("Dali");
    c1.attack("Jack");
    c1.displayInfo();
    c1.takeDamage(5);
    c1.displayInfo();
    c1.beRepaired(5);
    c1.displayInfo();
}
