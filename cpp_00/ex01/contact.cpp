# include <iostream>
#include "Contact.hpp"

// constructor
Contact::Contact()
{

}

// destructor
Contact::~Contact()
{

}

void Contact::createContact(void)
{
	std::cin.ignore();
	this->firstName = this->readInput("Please insert your first name: ");
	this->lastName = this->readInput("Please insert your last name: ");
	this->nickName = this->readInput("Please insert your nickname: ");
	this->phoneNumber = this->readInput("Please insert your phone number: ");
	this->darkestSecret = this->readInput("Please insert your darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::checkLength(std::string str)
{
	if(str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::printInfo(int index)
{
	std::cout << "|" << std::setw(10) << index + 1 << std::flush;
	std::cout << "|" << std::setw(10) << checkLength(this->firstName) << std::flush;
	std::cout << "|" << std::setw(10) << checkLength(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << checkLength(this->nickName) << std::flush;
	std::cout << "|" << std::setw(10) << checkLength(this->phoneNumber) << std::flush;
	std::cout << "|" << std::setw(10) << checkLength(this->darkestSecret) << std::endl;
	std::cout << std::endl;
}

std::string Contact::readInput(std::string str)
{
	std::string input = "";
	bool status = false;

	while(!status)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if(!input.empty() && std::cin.good())
			status = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input, try a different one." << std::endl;
		}
	}
	return(input);
}
