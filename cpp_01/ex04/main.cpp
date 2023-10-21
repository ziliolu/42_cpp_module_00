#include <iostream>
#include <fstream>
#include <string>

int err(std::string str)
{
    std::cout << str << std::endl;
    return 1;
}

int replace(char **argv, std::string buffer)
{
	std::ofstream outfile;
	int s1_found;

	outfile.open(std::string(argv[1]).append(".replace"), std::ios::out);
	if(outfile.fail())
		return 1;

	for(int i = 0; i < buffer.size(); i++)
	{
		s1_found = buffer.find(argv[2], i);
		if(s1_found == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]). size() - 1;
		}
		else
			outfile << buffer[i];
	}
	outfile.close();
	return 0; 

}
int main(int argc, char **argv)
{
	if(argc != 4)
		return err("error: invalid number of arguments");

	std::string infile = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::fstream file;
	file.open(infile);
	
	if(!file)
		return err("error: impossible to open the file"), err(infile), err("\n");
	char buffer[1000];
	file.read(buffer, sizeof(buffer));

	std::cout << "buf: " << buffer << std::endl;
	return replace(argv, buffer); 
}