#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "../includes/ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:

        // Constructor & Destructor
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

        //  Member functions
        void guardGate();
};

#endif