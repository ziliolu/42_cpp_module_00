#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
#include <iomanip>

class Contact {

    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
        ~Contact();
        void createContact();
        void printInfo(int index);
        void display();
        std::string readInput(std::string str);
        std::string checkLength(std::string str);
        inline std::string getFirstName(){
            return this->firstName;
        }

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName; 
        std::string phoneNumber;
        std::string darkestSecret;
};

#endif