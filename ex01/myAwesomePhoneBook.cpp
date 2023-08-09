#include "PhoneBook.h"
#include "Contact.h"
# include <iostream>

void PhoneBook::addContact(std::string name, std::string phoneNumber)
{
    Contact contact;

    contact.name = name;
    contact.phoneNumber = phoneNumber;
    contacts[currentSize] = contact;
    if(currentSize < 7)
        currentSize++;
}

void displayPrompt(PhoneBook PhoneBook)
{
    std::string cmd;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;


    std::cout   << "\nWelcome to your Phone Book!\n\n"
                << "Please write one of the following commands:\n\n"
                << "ADD - for saving a new contact\n"
                << "SEARCH - for displaying a specific contact\n"
                << "EXIT - for exiting your phone book :(\n\n";

    std::cin >> cmd;
    if(cmd == "ADD")
    {
        std::cout << "Please type first name: ";
        std::cin >> firstName;
        std::cout << "Please type last name: ";
        std::cin >> lastName;
        std::cout << "Please type nickname: ";
        std::cin >> nickname;
        std::cout << "Please type phone number: ";
        std::cin >> phoneNumber;
        std::cout << "Please type darkest secret: ";
        std::cin >> darkestSecret;

        PhoneBook.addContact(firstName, phoneNumber);
    }
}

int main()
{
    PhoneBook phoneBook;
    int i = 0;

    displayPrompt(phoneBook);
    while(i <= 7)
    {
        std::cout << phoneBook.contacts[i].name + " - " + phoneBook.contacts[i].phoneNumber + "\n";
        i++;
    }
}
