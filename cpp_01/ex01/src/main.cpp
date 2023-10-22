#include "../includes/Zombie.hpp"

int main()
{
    Zombie *zombies;
    int     N;

    N = 3;
    zombies = zombieHorde(N, "Jack");

    for(int i = 0; i < N; i++)
        zombies[i].announce();
    
    delete[] zombies;
    return 0;
}