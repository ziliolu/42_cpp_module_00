#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& other);
        const Cure& operator=(const Cure& other);
        std::string const& getType() const;
        //virtual Cure* clone() const = 0;
        //virtual void use(ICharacter& target);
};

#endif