#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"

class PhoneBook {

    public:
        Contact contacts[9];

        PhoneBook();
        ~PhoneBook();
        void    addContact(void);
        void    displayContacts();
        void    searchContact();
        void    displayPrompt(void);

};


#endif