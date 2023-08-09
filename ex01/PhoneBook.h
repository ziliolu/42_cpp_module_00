#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.h"

class PhoneBook {

    public:
        void addContact(std::string name, std::string phoneNumber); 
        Contact contacts[9];
        int currentSize = 0;
};

#endif