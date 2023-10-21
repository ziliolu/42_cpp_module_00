#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{    
    std::string str; 
    for(int i = 1; i < argc; i++)
    {
        str = argv[i];
        for(int j = 0; j < str.size(); j++)
            std::cout << char(toupper(str[j]));
    }
    if(!argv[1])
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
        std::cout << std::endl;
}
