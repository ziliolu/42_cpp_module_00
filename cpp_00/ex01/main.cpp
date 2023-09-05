#include "PhoneBook.hpp"
#include "Contact.hpp"
# include <iostream>





int main()
{
    PhoneBook phoneBook;
    std::string cmd;

    
    phoneBook.displayPrompt();
    while(cmd != "EXIT")
    {
        std::cout << "myPhoneBook 📞 > ";
        std::cin >> cmd;
        if(cmd == "ADD")
            phoneBook.addContact();
        else if(cmd == "SEARCH")
        {
            phoneBook.displayContacts();
            phoneBook.searchContact();
        }
    }
}
