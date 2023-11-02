#include <iostream>
#include <fstream>
#include <cstdlib>

std::string ft_replace_line(std::string line, std::string s1, std::string s2)
{
    size_t i = 0;
    while(1)
    {
        i = line.find(s1, i);
        if(i == std::string::npos)
            break;
        line.erase(i, s1.length());
        line.insert(i, s2);
        i += s2.length();
    }
    return (line);
}

int main(int argc, char **argv)
{
	if(argc != 4)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return (EXIT_FAILURE);
    }

	std::string s1 = argv[2];
	std::string s2 = argv[3];
    std::string outfile_str = std::string(argv[1]).append(".replace");
    const char *infile_char = argv[1];
    const char *outfile_char = outfile_str.c_str();

	std::ifstream infile;
    std::ofstream outfile;

    infile.open(infile_char);
    outfile.open(outfile_char);
    if(!infile.is_open() || !outfile.is_open())
    {
        std::cout << "Error: impossible to open a file" << std::endl;
        return (EXIT_FAILURE);
    }
    std::string line;
    while(getline(infile, line))
    {
        line = ft_replace_line(line, s1, s2);
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return (0);
}