#include "../includes/PmergeMe.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>

// Print the lists
void info(const std::vector<int>& main, const std::vector<int>& pend) {
    std::cout << "Main list: ";
    for (size_t i = 0; i < main.size(); ++i) {
        std::cout << main[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Pend list: ";
    for (size_t i = 0; i < pend.size(); ++i) {
        std::cout << pend[i] << " ";
    }
    std::cout << std::endl;
}

// Print pairs of elements
void print_pairs(const std::vector<std::pair<int, int> >& pairs) {
    std::cout << "Pairs: ";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    std::cout << std::endl;
}
void jacobsthal_insert(std::vector<int>& main, std::vector<int>& pend) {
    // Generate the Jacobsthal sequence up to the size of the main list
    std::vector<unsigned int> jacobsthal_sequence;
    jacobsthal_sequence.push_back(1); // J(0)
    jacobsthal_sequence.push_back(3); // J(1)
    
    // Generate the sequence until it's large enough
    while (jacobsthal_sequence.back() < main.size()) {
        int next_value = 2 * jacobsthal_sequence[jacobsthal_sequence.size() - 1] + jacobsthal_sequence[jacobsthal_sequence.size() - 2];
        jacobsthal_sequence.push_back(next_value);
    }

    // Start inserting pend elements in reverse order (smallest first)
    for (int i = pend.size() - 1; i >= 0; --i) {
        int val = pend[i];
        bool inserted = false;
        
        // Loop through the Jacobsthal sequence
        for (size_t j = 0; j < jacobsthal_sequence.size(); ++j) {
            // If the current Jacobsthal number is within bounds of the main list
            if (static_cast<unsigned long>(jacobsthal_sequence[j]) <= main.size()) {
                // Find the correct position for insertion using lower_bound
                std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), val);
                
                // Insert the element at the correct position
                std::cout << "Inserted " << val << " at index " << (it - main.begin()) << std::endl;
                main.insert(it, val);
                pend.erase(pend.begin() + i); // Remove the inserted element from pend
                
                // Print the insertion and position
                inserted = true;
                info(main, pend);
                break; // Exit loop if inserted
            }
        }
        
        // If no insertion was done (jacobsthal_sequence was exhausted), push to back
        if (!inserted) {
            main.push_back(val);
        }
    }
}

// Function to perform the Push Swap sorting with Jacobsthal insertion
std::vector<int> push_swap_sort(std::vector<int>& nums) {
    // Base case: If the list has one or zero elements, it’s already sorted
    if (nums.size() <= 1) {
        return nums;
    }

    // Step 1: Create pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < nums.size(); i += 2) {
        pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
    }
    // If there's an odd element out, handle it separately
    if (nums.size() % 2 != 0) {
        pairs.push_back(std::make_pair(nums.back(), -1));  // Pair last element with -1
    }

    print_pairs(pairs);

    // Step 2: Sort each pair and split into 'main' and 'pend'
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (pairs[i].second == -1) {
            pend.push_back(pairs[i].first);
        } else {
            int smaller = std::min(pairs[i].first, pairs[i].second);
            int larger = std::max(pairs[i].first, pairs[i].second);
            pend.push_back(smaller);
            main.push_back(larger);
        }
    }

    info(main, pend);

    // Step 3: Recursively sort the 'main' list
    if (main.size() > 1) {
        main = push_swap_sort(main);
    }

    std::cout << "After recursive sorting: " << std::endl;
    info(main, pend);

    // Step 4: Generate Jacobsthal sequence for inserting pend

    // Step 5: Recursively insert pend elements into the main list using Jacobsthal sequence
    std::cout << "Jacobsthal recursive insertion" << std::endl;
    jacobsthal_insert(main, pend);
    return main;
}

int main() {
    // Initial unsorted list
    std::vector<int> nums;
    nums.push_back(9);
    nums.push_back(7);
    nums.push_back(15);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(11);
    nums.push_back(5);
    nums.push_back(14);
    nums.push_back(6);
    nums.push_back(20);
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(10);
    nums.push_back(12);
    nums.push_back(4);
    nums.push_back(19);
    nums.push_back(13);
    nums.push_back(18);
    nums.push_back(16);

    std::cout << "Before list: ";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    // Call the sorting function
    std::vector<int> sorted_nums = push_swap_sort(nums);

    // Print the sorted list
    std::cout << "Sorted List: ";
    for (size_t i = 0; i < sorted_nums.size(); ++i) {
        std::cout << sorted_nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
