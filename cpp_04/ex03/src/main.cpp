#include "../includes/ICharacter.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"


int main()
{
        Cure cure1;
        std::cout << cure1.getType()<< std::endl;

        Ice ice1;
        std::cout << ice1.getType() << std::endl;
}