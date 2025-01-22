#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <sstream> 
#include <fstream>

#include "Colors.hpp"
#include "Utils.hpp"

class BitcoinExchange {

    private:
        std::map<std::string, float> database;
        std::map<std::string, float> inputFile;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &inputFilePath);
        BitcoinExchange(const BitcoinExchange &src);
        const BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDatabase();
        void printMap(std::map<std::string, float> map);
        std::map<std::string, float>getDatabase() const;
        std::map<std::string, float>getInputFile() const;
        void calculateRates(const std::string &inputFilePath);
};

std::string trim(std::string str);

#endif