#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] Default constructor called" << std::endl;
}
Brain::Brain(const Brain& other)
{
    std::cout << "[Brain] Copy constructor called" << std::endl;
    this->setIdeas(other.ideas);
}
Brain::~Brain()
{
    std::cout << "[Brain] Destructorcalled" << std::endl;
}
const Brain& Brain::operator=(const Brain& other)
{
    std::cout << "[Brain] Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->setIdeas(other.ideas);
    }
    return (*this);
}

void Brain::setIdeas(const std::string *newIdeas)
{
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = newIdeas[i];
    }
}
std::string *Brain::getIdeas()
{
    return this->ideas;
}