#include <iostream>
#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::~Contact(){}

void Contact::createContact()
{
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
	std::cout << std::endl;
}

void Contact::display()
{
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickName << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
	std::cout << std::endl;
}
std::string Contact::readInput(std::string str)
{
	std::string input;

	while(input.empty())
    {
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if(!std::cin.good())
		{
            if(std::cin.eof())
                std::exit(130);
			std::cin.clear();
			std::cout << "Invalid input, try a different one." << std::endl;
		}
	}
	return(input);
}
