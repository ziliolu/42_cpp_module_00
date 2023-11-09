#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap c1("Dali");
    ClapTrap c2("Maria");
    c2.takeDamage(10);
    c1.takeDamage(1);
    c1.displayInfo();
    c2.displayInfo();

    ClapTrap c3 (c2);
    c3.displayInfo();
    c2.displayInfo();

    c2 = c1;
    c1.displayInfo();
    c2.displayInfo();
}
