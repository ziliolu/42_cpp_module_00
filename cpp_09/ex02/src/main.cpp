#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {
    std::vector<int> unsortedNumbers;

    if (argc != 2) {
        std::cout << "Error. Try ./PmergeMe <number_sequence>" << std::endl;
        return -1;
    }

    std::string numbersInput = argv[1];
    std::stringstream ss(numbersInput);
    int number;
    while (ss >> number) {
        unsortedNumbers.push_back(number);
        if (ss.peek() == ',') {
            ss.ignore();
        }
    }

    // Separate the sequence into pairs using the PmergeMe class
    std::vector<std::pair<int, int> > pairs = PmergeMe::separate_into_pairs(unsortedNumbers);

    // Print the pairs
    for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;

    return 0;
}