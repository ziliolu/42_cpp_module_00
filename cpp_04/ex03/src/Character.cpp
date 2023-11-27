#include "../includes/Character.hpp"

Character::Character()
{
    //std::cout << "[CHARACTER] Default constructor called" << std::endl;
    this->_name = "Default name";
    for(int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}
Character::Character(std::string name)
{
    //std::cout << "[CHARACTER] Name constructor called: Character " << name << " created" << std::endl;
    this->_name = name;
    for(int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}
Character::Character(const Character& src) : _name(src._name)
{
    //std::cout << "[CHARACTER] Copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(src._inventory[i] != NULL)
            _inventory[i] = src._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
        if(this->_inventory[i])
            delete this->_inventory[i];
    //std::cout << "[CHARACTER] Destructor called: Character " << this->_name << " destroyed" << std::endl;
}

const Character& Character::operator=(const Character& other)
{
    //std::cout << "[CHARACTER] Assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_name = other._name;
    }
    return (*this);
}

void Character::equip(AMateria* m)
{
    //std::cout << "[CHARACTER] Equipping..: ";
    for (int i = 0; i < 4; i++)
    {
        if(this->_inventory[i] == NULL && m != NULL)
        {
            //std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
            this->_inventory[i] = m;
            return ; 
        }
    }
    //std::cout << "It wasn't possible to equip '" << this->_name << "'" << std::endl;
}

void Character::unequip(int idx)
{
    //std::cout << "[CHARACTER] Unequipping.." << std::endl;
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if(this->_inventory[idx])
        this->_inventory[idx]->use(target);
}

std::string const& Character::getName() const
{
    return (this->_name);
}