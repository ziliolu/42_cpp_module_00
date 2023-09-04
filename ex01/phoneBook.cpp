#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream> 

// constructor
PhoneBook::PhoneBook()
{

}

// destructor
PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact(void)
{
    static int i;
    this->contacts[i % 8].createContact();
    i++;
}

void PhoneBook::displayPrompt(void)
{
    std::cout   << "\nWelcome to your Phone Book!\n\n"
                << "Please write one of the following commands:\n\n"
                << "ADD - for saving a new contact\n"
                << "SEARCH - for displaying a specific contact\n"
                << "EXIT - for exiting your phone book :(\n\n";
}

void PhoneBook::displayContacts(void)
{
    for(int i = 0; i < 8; i++)
    {
        contacts[i].printInfo(i);
    }
    std::cout << std::endl;
}

void PhoneBook::searchContact(void)
{
    int input;


    while(1)
    {
        std::cout << "Please insert a valid contact's index: ";
        std::cin >> input;
        input -= 1;
        if(contacts[input].firstName.empty())
        {
            std::cin.clear();
            std::cout << "Error: Contact doesn't exist yet. " << std::endl;
        }
        else if(input >= 0 && input < 8)
        {
            std::cout << std::endl << "Index: " << input  + 1 << std::endl;
            std::cout << "First name: " << contacts[input].firstName << std::endl;
            std::cout << "Last name: " << contacts[input].lastName << std::endl;
            std::cout << "Nickname: " << contacts[input].nickName << std::endl;
            std::cout << "Phone number: " << contacts[input].phoneNumber << std::endl;
            std::cout << "Darkest secret: " << contacts[input].darkestSecret << std::endl;
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cin.clear();
            std::cout << "Error: Invalid index. Please insert a valid number between 1 and 8." << std::endl;
        }
    }


}