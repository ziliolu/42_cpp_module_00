template <typename T>
PmergeMe<T>::PmergeMe() {
    std::cout << "PmergeMe constructor" << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other) : _main(other._main), _pend(other._pend) {
    std::cout << "PmergeMe copy constructor" << std::endl;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {
    std::cout << "PmergeMe destructor" << std::endl;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& other) {
    if (this != &other) {
        _main = other._main;
        _pend = other._pend;
    }
    std::cout << "PmergeMe assignment operator" << std::endl;
    return *this;
}

template <typename T>
std::vector<std::pair<int, int> > PmergeMe<T>::separate_into_pairs(const std::vector<int>& container) {
    std::cout << "1. Merging the numbers into pairs" << std::endl;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
        int first = container[i];
        int second = (i + 1 < container.size()) ? container[i + 1] : 0; // Assuming 0 as a default value for the second element if it doesn't exist
        pairs.push_back(std::make_pair(first, second));
    }
    print_pairs(pairs);
    return pairs;
}

template <typename T>
std::vector<std::pair<int, int> > PmergeMe<T>::sort_pairs(std::vector<std::pair<int, int> >& pairs) {
    std::cout << "2. Sorting the pairs" << std::endl;
    for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        if (it->first > it->second) {
            std::swap(it->first, it->second);
        }
    }
    print_pairs(pairs);
    return pairs;
}

template <typename T>
void PmergeMe<T>::add_to_main_and_pend(std::vector<std::pair<int, int> >& pairs) {
    for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        _main.push_back(it->second);
        _pend.push_back(it->first);
    }

    print_containers(_main, _pend);
}

template <typename T>
void PmergeMe<T>::print_pairs(const std::vector<std::pair<int, int> >& pairs) {
    for (typename std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;
}

template <typename T>
T PmergeMe<T>::recursive_sort(T& nums) {
    // Base case: if the container has one or no elements, it's already sorted
    if (nums.size() <= 1) {
        return nums;
    }

    // Step 1: Form pairs
    typedef typename T::value_type ValueType; // Type of elements in the container
    std::vector<std::pair<ValueType, ValueType> > pairs;

    typename T::iterator it = nums.begin();
    while (it != nums.end()) {
        ValueType first = *it;
        ++it;
        if (it != nums.end()) {
            ValueType second = *it;
            pairs.push_back(std::make_pair(std::min(first, second), std::max(first, second)));
            ++it;
        } else {
            pairs.push_back(std::make_pair(first, first)); // Use the same value for both elements
        }
    }

    // Step 2: Extract leaders (larger elements of each pair)
    T leaders;
    typename std::vector<std::pair<ValueType, ValueType> >::const_iterator pair_it;
    for (pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
        leaders.push_back(pair_it->second);
    }

    // Recursive call
    leaders = recursive_sort(leaders);

    // Step 3: Merge the sorted leaders back with the smaller elements
    T sorted;
    typename T::iterator leader_it = leaders.begin();
    for (pair_it = pairs.begin(); pair_it != pairs.end(); ++pair_it) {
        sorted.push_back(pair_it->first);
        if (leader_it != leaders.end()) {
            sorted.push_back(*leader_it);
            ++leader_it;
        }
    }

    // If there are remaining leaders, add them to the sorted list
    while (leader_it != leaders.end()) {
        sorted.push_back(*leader_it);
        ++leader_it;
    }

    return sorted;
}

template <typename T>
void PmergeMe<T>::print_containers(T main, T pend) const {
    std::cout << "Main container: ";
    for (typename T::const_iterator it = main.begin(); it != main.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Pend container: ";
    for (typename T::const_iterator it = pend.begin(); it != pend.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
const T& PmergeMe<T>::get_main() const {
    return _main;
}

template <typename T>
const T& PmergeMe<T>::get_pend() const {
    return _pend;
}