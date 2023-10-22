#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie {

    public: 
        void announce(void);
        void setName(std::string name);
        std::string getName(void);
        Zombie();
        ~Zombie();
    
    private:
        std::string _name;

};

void    randomChum(std::string name);
Zombie *newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif