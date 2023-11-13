#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongDog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    int N = 6;
    Animal *animals[N];

    std::cout << std::endl << "---- Creating animals -----" << std::endl << std::endl;
    for(int i = 0; i < N; i++)
    {
        std::cout << "[ " << i << " ]" << std::endl;
        if(i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl << "---- Deleting animals -----" << std::endl << std::endl;
    for(int i = 0; i < N; i++)
    {
        std::cout << "[ " << i << " ]" << std::endl;
        delete animals[i];
    }
}