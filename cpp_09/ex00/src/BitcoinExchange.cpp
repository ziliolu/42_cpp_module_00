#include "../includes/BitcoinExchange.hpp"

void BitcoinExchange::loadDatabase()
{
    std::string line;
    std::ifstream file("data.csv");
    int errorLine = 0;
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file."  << std::endl;
        return;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double value;

        if (std::getline(ss, date, ',') && ss >> value) {
            database[date] = value;
        } 
        else
            errorLine++;
    }

    if (database.size() != 0) {
        std::cout << "Database successfully added to the database. ";
        if (errorLine != 0)
            std::cout << errorLine << " line(s) were invalid." << std::endl;
        else 
            std::cout << std::endl;
    }
    file.close();
}


// Default constructor
BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
    loadDatabase();
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = src;
}

// Parameterized constructor
BitcoinExchange::BitcoinExchange(const std::string &inputFilePath) {
    std::cout << "BitcoinExchange parameterized constructor called" << std::endl;
    loadDatabase();
    calculateRates(inputFilePath);
}

void BitcoinExchange::calculateRates(const std::string &inputFilePath)
{
    std::string line;
    std::ifstream file(inputFilePath.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file."  << std::endl;
        return;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double value;

        std::getline(ss, date, '|') && ss >> value;

        date = Utils::trim(date);
        if (!Utils::isValidDate(date)) {
            std::cout << "Invalid Date: " << date << std::endl;
        } else if (!Utils::isValidValue(value)) {
            std::cout << "Date: " << date << ", Invalid Value: " << value << std::endl; 
        } else {
            std::map<std::string, float>::iterator it = database.find(date);
            if (it != database.end()) {
                double rate = it->second;
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            } 
            else {
                std::map<std::string, float>::iterator it = database.lower_bound(date);
                if (it != database.begin() && (it == database.end() || it->first != date)) {
                    --it;
                }
                if (it != database.end()) {
                    double rate = it->second;
                    std::cout << date << " => " << value << " = " << value * rate << std::endl;
                } else {
                    std::cerr << "Error: No valid date found in database." << std::endl;
                }
            }
        }
    }
    
    file.close();
}

// Assignment operator
const BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        std::cout << "BitcoinExchange assignment operator called" << std::endl;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::printMap(std::map<std::string, float> map)
{
    std::cout << "Printing database" << std::endl;
    std::map<std::string, float>::iterator it;
    for (it = map.begin(); it != map.end(); ++it) {
        std::cout << "Date: " << it->first << ", Rate: " << it->second << std::endl;
    }
}

std::map<std::string, float> BitcoinExchange::getDatabase() const {
    return database;
}

std::map<std::string, float> BitcoinExchange::getInputFile() const {
    return inputFile;
};