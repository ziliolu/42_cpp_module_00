#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public AAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);
        void makeSound() const;
        Brain *getBrain();
        void setBrain(Brain *brain);
};

#endif
