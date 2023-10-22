#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_weapon = NULL;
    this->_name = name;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{   
    this->_weapon = &weapon;
    this->_name = name;
}

HumanB::~HumanB()
{
    std::cout << "Human " << this->_name << " destroyed" << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack()
{
    if(this->_weapon->getType() != "")
        std::cout << this->_name << "attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << "Human " << this->_name << " has no weapon to attack!\n";
}