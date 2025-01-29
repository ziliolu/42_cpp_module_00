#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <utility>
#include <iostream>

template <typename T>
class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    std::vector<std::pair<int, int> > separate_into_pairs(const std::vector<int>& container);
    std::vector<std::pair<int, int> > sort_pairs(std::vector<std::pair<int, int> >& pairs);
    void add_to_main_and_pend(std::vector<std::pair<int, int> >& pairs);
    void print_pairs(const std::vector<std::pair<int, int> >& pairs);
    void print_containers(T main, T pend) const;
    
    T recursive_sort(T& nums);
   
    const T& get_main() const;
    const T& get_pend() const;

private:
    T _main;
    T _pend;
};

#include "../src/PmergeMe.tpp"
#endif // PMERGEME_HPP