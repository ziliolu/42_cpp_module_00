#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "../includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:

        // Constructor & Destructor
        FragTrap();
        FragTrap(std::string name);
        ~FragTrap();

        //  Member functions
        void highFivesGuys();

        // Getters
        std::string get_name() const;
        int get_hitPoints() const;
        int get_energyPoints() const;
        int get_attackDamage() const;

        // Setters
        void set_name(std::string name);
        void set_hitPoints(int hitPoints);
        void set_energyPoints(int energyPoints);
        void set_attackDamage(int attackDamage);
};

#endif