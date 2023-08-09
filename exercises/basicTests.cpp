// C++ TUTORIAL W3 SCHOOLS

#include <iostream>
using std::cout;
using std::cin;
using std::string;

int main()
{
    //declaring a sequence of characters (text)
    string firstName = "Luiza";
    string lastName = "Zilio";
    string myFullName = firstName + " " + lastName;
    string firstNameFriend;
    string lastNameFriend;
    string fullNameFriend;

    //declaring int in multiple forms
    int x = 10, y = 7, z = 10;
    int n1, n2, n3;
    n1 = n2 = n3 = 50;

    //const varibles which means unchangeable and read-only
    const int myAge = 21;

    //printing a value in the screen (see-out)
    cout << "My name is " << myFullName << " and I'm " << myAge << " years old\n";
    cout << "What is your first name? Type it please\n";

    //asking for input (see-in)
    cin >> firstNameFriend;
    cout << "And what is your last name? Type it please\n";
    cin >> lastNameFriend;

    //exploring append() function
    fullNameFriend = firstNameFriend.append(lastNameFriend);
    cout << "Nice! Your name is " << fullNameFriend << "\n";
    return 0;
}