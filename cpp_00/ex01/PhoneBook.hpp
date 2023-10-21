#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
#include <algorithm>
# include "Contact.hpp"

class PhoneBook {


    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        bool    displayContacts();
        bool    searchContact();
        void    displayPrompt();
    private:
        Contact contacts[9];

};
#endif