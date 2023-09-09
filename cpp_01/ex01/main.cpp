#include "Zombie.hpp"

int main()
{
    Zombie *zombies;
    int     N;
    int     i;

    N = 3;
    zombies = zombieHorde(N, "Jack");
    i = 0;
    while(i < N)
        zombies[i++].announce();
    
    delete[] zombies;
    return 0;
}