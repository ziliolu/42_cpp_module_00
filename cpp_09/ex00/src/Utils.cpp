#include "../includes/Utils.hpp"
#include <sstream>

std::string Utils::trim(const std::string& str) {
    
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

bool Utils::isValidValue(int value){
    if(value < 0 || value > 1000)
        return false;
    else 
        return true;
}

bool Utils::isValidDate(std::string date)
{
    std::istringstream ss(date.c_str());
    int year, month, day;
    char delimiter1, delimiter2;

    if (!(ss >> year >> delimiter1 >> month >> delimiter2 >> day)) {
        return false;
    }

    if (delimiter1 != '-' || delimiter2 != '-') {
        return false;
    }

    if (year < 1900 || year > 50000){
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    if (day < 1 || day > 31) {
        return false;
    }

    // Check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    // Check for February
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day == 29 && !isLeapYear)) {
            return false;
        }
    }

    return true;
}

