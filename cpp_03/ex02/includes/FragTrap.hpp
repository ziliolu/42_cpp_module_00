#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "../includes/ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:

        // Constructor & Destructor
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();

        //  Member functions
        void highFivesGuys();
};

#endif