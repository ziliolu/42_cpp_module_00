#include "PhoneBook.hpp"

std::string trim(std::string str)
{
    std::size_t start = str.find_first_not_of(" \t\n\r");
    std::size_t end = str.find_last_not_of(" \t\n\r");
    if(start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

int main() {

	PhoneBook phoneBook;
    std::string cmd;
    std::string cmd_trimmed;
	phoneBook.displayPrompt();
	while(cmd_trimmed != "EXIT")
	{
		std::cout << "myPhoneBook 📞 > ";
		std::istringstream iss(cmd);
        std::getline(std::cin, cmd, '\n');
        cmd_trimmed = trim(cmd);
        if (std::cin.eof())
            break;
		if(cmd_trimmed == "ADD")
			phoneBook.addContact();
		else if(cmd_trimmed == "SEARCH")
		{
			if(phoneBook.displayContacts())
			{
				if(!phoneBook.searchContact())
                    break;
			}
		}
		std::cin.clear();
	}
}