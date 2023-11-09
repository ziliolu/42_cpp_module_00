#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

    protected:
    
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        bool _isDead;

    public:

        //Getters
        std::string get_name() const;
        int get_hitPoints() const;
        int get_energyPoints() const;
        int get_attackDamage() const;

        //Setters
        void set_name(std::string name);
        void set_hitPoints(int hitPoints);
        void set_energyPoints(int energyPoints);
        void set_attackDamage(int attackDamage);

        //Constructor & Destructor
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();

        //Member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void displayInfo();
        bool checkDeath();

        //Overload operations
        ClapTrap& operator=(const ClapTrap& other);
};

#endif