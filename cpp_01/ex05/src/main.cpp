#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Please insert an argument: debug, info, warning or error" << std::endl;
        return (1);
    }; 

    Harl harl;
    std::string arg = argv[1];
    std::string levels[4] = {"debug", "info", "warning", "error"};

    for(int i = 0; i < 4; i++)
    {
        if(arg == levels[i])
        {
            harl.complain(levels[i]);
            return (0);
        }
    }
    std::cout << "Invalid argument" << std::endl;     
}