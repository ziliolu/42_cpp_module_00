#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>

class ICharacter 
{
    private:
        std::string _name;
    public:
        ICharacter();
        ICharacter(std::string _name);
        ICharacter(const ICharacter& other);
        ~ICharacter();
        const ICharacter& operator=(const ICharacter& other);

        std::string getName();
        void setName(std::string name);
};

#endif