#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "../includes/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:

        // Constructor & Destructor
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

        //  Member functions
        void guardGate();
        void attack(const std::string& target);
};  

#endif