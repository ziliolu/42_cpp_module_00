#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <utility> // for std::make_pair

PmergeMe::PmergeMe() {
    std::cout << "PmergeMe constructor" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    (void)other;
    std::cout << "PmergeMe copy constructor" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    std::cout << "PmergeMe assignment operator" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe destructor" << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::separate_into_pairs(const std::vector<int>& container) {
    std::cout << "1. Merging the numbers into pairs" << std::endl;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = (i + 1 < container.size()) ? container[i + 1] : 0; // Assuming 0 as a default value for the second element if it doesn't exist
        pairs.push_back(std::make_pair(first, second));
    }
    return pairs;
}