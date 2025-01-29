#include "../includes/PmergeMe.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <number_sequence>" << std::endl;
        return 1;
    }

    std::vector<int> input;
    std::stringstream ss(argv[1]);
    int number;
    while (ss >> number) {
        input.push_back(number);
    }

    PmergeMe<std::vector<int> > pmergeme;

    // Separate the sequence into pairs
    std::vector<std::pair<int, int> > sortedPairs = pmergeme.separate_into_pairs(input);

    // Sort the pairs
    sortedPairs = pmergeme.sort_pairs(sortedPairs);

    // Add to main and pend containers
    pmergeme.add_to_main_and_pend(sortedPairs);

    // Create non-const copies of the containers
    std::vector<int> pendCopy = pmergeme.get_pend();
    std::vector<int> mainCopy = pmergeme.get_main();

    std::cout << "Recursive sort called" << std::endl;
    // Sort the containers
    std::vector<int> sortedPend = pmergeme.recursive_sort(pendCopy);
    std::vector<int> sortedMain = pmergeme.recursive_sort(mainCopy);

    // Print sorted containers
    pmergeme.print_containers(sortedMain, sortedPend);
    std::cout << std::endl;

    return 0;
}