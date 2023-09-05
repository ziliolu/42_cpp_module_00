#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
#include <iomanip>

class Contact {

    public:
        std::string firstName;
        std::string lastName;
        std::string nickName; 
        std::string phoneNumber;
        std::string darkestSecret;

        Contact();
        ~Contact();
        void createContact(void);
        void printInfo(int index);
        std::string readInput(std::string str);
        std::string checkLength(std::string str);
};

#endif