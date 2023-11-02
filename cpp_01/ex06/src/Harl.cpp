#include "../includes/Harl.hpp"

Harl::Harl(){}

void Harl::debug()
{
    std::cout   << "[ DEBUG ]" << std::endl
                << "I love having extra bacon for my "
                << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
                << "I really do!" << std::endl;
}

void Harl::info()
{
    std::cout   << "[ INFO ]" << std::endl
                << "I cannot believe adding extra bacon "
                << "costs more money. You didnt put enough "
                << "bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout   << "[ WARNING ]" << std::endl
                << "I think I deserve to have some extra bacon for free. "
                << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout   << "[ ERROR ]" << std::endl
                << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels_str[4] = {"debug", "info", "warning", "error"};
    void (Harl::*levels_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int level_nbr = -1;
    for(int i = 0; i < 4; i++)
    {
        if(level == levels_str[i])
            level_nbr = i;
    }
    switch(level_nbr)
    {
        case 0:
            (this->*levels_ptr[level_nbr++])();
        case 1: 
            (this->*levels_ptr[level_nbr++])();
        case 2: 
            (this->*levels_ptr[level_nbr++])();
        case 3:
            (this->*levels_ptr[level_nbr])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}