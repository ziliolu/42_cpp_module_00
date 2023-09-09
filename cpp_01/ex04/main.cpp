#include <iostream>
#include <fstream>

int err(std::string str)
{
    std::cout << str << std::endl;
    return 1;
}
int main(int argc, char **argv)
{
	if(argc != 4)
		return err("error: invalid number of arguments");

	std::string infile = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::fstream file;
	std::ifstream file_replace;
	file.open(infile);
	file_replace.open(infile.append(".replace"), std::ios::out);
	if(infile.fail())
		return err("error: impossible to open the file"), err(filename);
	char buffer[300];
	file.read(buffer, sizeof(buffer));

	std::cout << "buf: " << buffer << std::endl;

	int i = 0;
	while(buffer[i])
	{
		if()
	}
}