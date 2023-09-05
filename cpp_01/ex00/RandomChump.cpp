#include "Zombie.hpp"

void randomChum(std::string name)
{
    Zombie *zombie = newZombie(name);
    zombie->announce();
    delete zombie;
}