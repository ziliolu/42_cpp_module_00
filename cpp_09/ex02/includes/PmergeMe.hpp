#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <utility> // for std::pair

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static std::vector<std::pair<int, int> > separate_into_pairs(const std::vector<int>& container);
};

#endif // PMERGEME_HPP