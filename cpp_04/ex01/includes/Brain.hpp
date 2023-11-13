#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
class Brain 
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        const Brain& operator=(const Brain& other);
        void setIdeas(const std::string *newIdeas);
        std::string *getIdeas();
};

#endif