#include "../includes/Harl.hpp"
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }

    Harl myHarl;
    myHarl.complain(argv[1]);
    return (EXIT_SUCCESS);
}