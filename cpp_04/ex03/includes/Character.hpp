#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];

    public:
        Character();
        Character(std::string name);
        Character(const Character& src);
        ~Character();
        const Character& operator=(const Character& other);
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif