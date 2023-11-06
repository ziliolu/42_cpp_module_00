#include "../includes/Zombie.hpp"

int main()
{
    std::cout << "Creation of first Zombie manually (in the stack)" << std::endl;
    {
        Zombie manual_zombie("Manual");
        manual_zombie.announce();
    }
    std::cout << "Creation of second Zombie (with heap allocation)" << std::endl;
    {
        Zombie *heap_zombie = newZombie("Heap");
        heap_zombie->announce();
        delete heap_zombie;
    }
    {
        std::cout << "Creation of third Zombie (in the stack)" << std::endl;
        randomChump("Stack");
    }
}