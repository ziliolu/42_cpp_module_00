#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream> 

std::string trim(std::string str);

PhoneBook::PhoneBook(){}
PhoneBook::~PhoneBook(){}

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

bool PhoneBook::displayContacts(void)
{
    int display = 0;
    std::cout << std::endl;
    if(contacts[0].getFirstName().empty())
    {
        std::cout << "Ops! Your Phone Book is still empty. Let's add some contacts!" << std::endl << std::endl;
        return false;
    }
    
    std::cout << "|" << std::setw(10) << "index" << std::flush;
    std::cout << "|" << std::setw(10) << "name" << std::flush;
    std::cout << "|" << std::setw(10) << "last name" << std::flush;
    std::cout << "|" << std::setw(10) << "nickname" << std::flush << std::endl;

    for(int i = 0; i < 8; i++)
    {
        if(!contacts[i].getFirstName().empty())
        {
            contacts[i].printInfo(i);
            display++;
        }
    }
    std::cout << std::endl;
    return true;
}

bool PhoneBook::searchContact(void)
{
    std::string stringInput;
    int intInput;
    while(true)
    {
        std::cout << "Please insert a valid contact's index: ";
        std::cin.clear();
        getline(std::cin, stringInput);
        std::stringstream stream(stringInput);
        stream >> intInput;
        if (std::cin.eof())
            exit(130);
        try {
            if(intInput > 0 && intInput < 8)
            {
                intInput -= 1;
                std::cin.clear();
                if(contacts[intInput].getFirstName().empty())
                    std::cout << "Sorry, this contact doesn't exist yet. " << std::endl;
                else
                {
                    std::cout << std::endl << "Index: " << intInput  + 1 << std::endl;
                    contacts[intInput].display();
                    break;
                }
            }
            else
            {
                std::cin.clear();
                std::cout << "Error: Invalid index. Please insert a valid number between 1 and 8." << std::endl;
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cin.clear();
            std::cout << "Error: Invalid argument. Please insert a valid number between 1 and 8." << std::endl;
        }
    }
    return true;
}