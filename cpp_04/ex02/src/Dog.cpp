#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "[Dog] Default constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[Dog] Destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "[Dog] Copy assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;

    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "[Dog] Au au au" << std::endl;
}

void Dog::setBrain(Brain *brain)
{
    if(this->brain)
        delete brain;
    this->brain = brain;
}

Brain *Dog::getBrain()
{
    return this->brain;
}