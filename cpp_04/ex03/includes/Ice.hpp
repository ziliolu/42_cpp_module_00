#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        const Ice& operator=(const Ice& other);
        Ice(const Ice& other);
        std::string const& getType() const;
        //virtual Ice* clone() const = 0;
        //virtual void use(ICharacter& target);
};

#endif