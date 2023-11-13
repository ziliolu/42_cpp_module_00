#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongDog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    std::cout << std::endl << "----- Right animal test -----" << std::endl << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    dog->makeSound(); //will output the cat sound!
    cat->makeSound();
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << std::endl << "----- Wrong animal test -----" << std::endl << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongDog = new WrongDog();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongDog->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongDog->makeSound(); //will output the cat sound!
    wrongCat->makeSound();
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;
    delete wrongDog;
    return 0;
}