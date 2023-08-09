#include <iostream>

using std::cout;

//The break statement can also be used to jump out of a loop

int main()
{
    int day = 7;

    switch(day)
    {
        case 1: 
           cout << "Monday\n";
           break; 
        case 2:
           cout << "Tuesday\n";
            break;
        case 3: 
            cout << "Wednesday\n";
            break;
        case 4:
            cout << "Thurday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        default:
            cout << "Looking forward to the weekend!\n";
    }
}