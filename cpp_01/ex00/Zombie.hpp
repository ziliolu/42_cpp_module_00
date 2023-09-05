#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

    public: 
        void announce(void);
        void setName(std::string name);
        // void setIndex(int index);
        Zombie();
        ~Zombie();
    
    private:
        std::string _name;
        // int _index;

};

void    randomChum(std::string name);
Zombie *newZombie(std::string name);

#endif