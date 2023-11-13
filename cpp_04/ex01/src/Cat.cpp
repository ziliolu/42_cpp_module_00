#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] Default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] Copy constructor called" << std::endl;
    this->brain = other.brain;
}

Cat::~Cat()
{
    std::cout << "[Cat] Destructor called" << std::endl;
    delete this->brain;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "[Cat] Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->type = other.type;
        this->brain = other.brain;
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "[Cat] Miaaaaau" << std::endl;
}

void Cat::setBrain(Brain *brain)
{
    if(this->brain)
        delete brain;
    this->brain = brain;
}

Brain *Cat::getBrain()
{
    return this->brain;
}