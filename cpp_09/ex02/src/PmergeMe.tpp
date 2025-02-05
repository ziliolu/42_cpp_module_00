#include "../includes/PmergeMe.hpp"

template <typename T> PmergeMe<T>::PmergeMe(int argc, char **argv)
{
    startTimer();
    groupElements(argc, argv);
}

template <typename T> void PmergeMe<T>::groupElements(int argc, char **argv)
{
    int first, second;
    int i = 1;
    while (i < argc)
    {
        if (i == argc - 1)
        {
            pending.push_back(std::atoi(argv[i]));
            return;
        }

        first = std::atoi(argv[i]);
        second = std::atoi(argv[i + 1]);

        if (first >= second)
        {
            main.push_back(first);
            pending.push_back(second);
        }
        else
        {
            main.push_back(second);
            pending.push_back(first);
        }
        i += 2;
    }
}

template <typename T> int PmergeMe<T>::getSize() const
{
    return main.size();
}

template <typename T> T PmergeMe<T>::getMain() const
{
    return main;
}

template <typename T> T PmergeMe<T>::getPending() const
{
    return pending;
}

template <typename T> void PmergeMe<T>::printContainer(T container)
{
    typename T::iterator it = container.begin();
    while (it != container.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

template <typename T> void PmergeMe<T>::printPending()
{
    std::cout << "Pend: ";
    typename T::iterator it = pending.begin();
    while (it != pending.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

template <typename T> void PmergeMe<T>::printMain()
{
    std::cout << "Main:  ";
    typename T::iterator it = main.begin();
    while (it != main.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::mergeSort(int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

template <typename Container>
void PmergeMe<Container>::merge(int left, int mid, int right)
{
    Container leftMainContainer(main.begin() + left, main.begin() + mid + 1);
    Container rightMainContainer(main.begin() + mid + 1, main.begin() + right + 1);

    Container leftPendingContainer(pending.begin() + left, pending.begin() + mid + 1);
    Container rightPendingContainer(pending.begin() + mid + 1, pending.begin() + right + 1);

    typename Container::iterator mainIt = main.begin() + left;
    typename Container::iterator pendingIt = pending.begin() + left;

    typename Container::iterator leftMainIt = leftMainContainer.begin();
    typename Container::iterator leftPendingIt = leftPendingContainer.begin();
    typename Container::iterator rightMainIt = rightMainContainer.begin();
    typename Container::iterator rightPendingIt = rightPendingContainer.begin();

    // Merging main and pending containers
    while (leftMainIt != leftMainContainer.end() && rightMainIt != rightMainContainer.end()) {
        if (*leftMainIt <= *rightMainIt) {
            *mainIt = *leftMainIt;
            *pendingIt = *leftPendingIt;
            ++leftMainIt;
            ++leftPendingIt;
        } else {
            *mainIt = *rightMainIt;
            *pendingIt = *rightPendingIt;
            ++rightMainIt;
            ++rightPendingIt;
        }
        ++mainIt;
        ++pendingIt;
    }

    // Merge remaining elements from left side
    while (leftMainIt != leftMainContainer.end()) {
        *mainIt = *leftMainIt;
        *pendingIt = *leftPendingIt;
        ++leftMainIt;
        ++leftPendingIt;
        ++mainIt;
        ++pendingIt;
    }

    // Merge remaining elements from right side
    while (rightMainIt != rightMainContainer.end()) {
        *mainIt = *rightMainIt;
        *pendingIt = *rightPendingIt;
        ++rightMainIt;
        ++rightPendingIt;
        ++mainIt;
        ++pendingIt;
    }
}

template <typename Container>
void PmergeMe<Container>::insertIntoSortedList()
{
    if (pending.empty()) return;

    main.insert(main.begin(), pending.front());
    int i = 0;
    size_t jacobIter = 1;
    size_t distance = jacobsFormula(jacobIter) * 2;
    size_t insertCount = 1;

    while (i + distance < pending.size()) {
        int start = i;
        i += distance;
        while (i > start) {
            binaryInsert(0, i + insertCount - 1, pending[i]);
            ++insertCount;
            --i;
        }
        i += distance;
        ++jacobIter;
        distance = jacobsFormula(jacobIter) * 2;
    }

    int start = i;
    i = pending.size() - 1;
    while (i > start) {
        binaryInsert(0, i + insertCount - 1, pending[i]);
        ++insertCount;
        --i;
    }
}

template <typename Container>
void PmergeMe<Container>::binaryInsert(int left, int right, int number)
{
    if (left >= right) {
        if (main[left] > number) {
            main.insert(main.begin() + left, number);
        } else {
            main.insert(main.begin() + left + 1, number);
        }
        return;
    }

    int mid = left + (right - left) / 2;
    if (main[mid] == number) {
        main.insert(main.begin() + mid, number);
        return;
    } else if (number > main[mid]) {
        binaryInsert(mid + 1, right, number);
    } else {
        binaryInsert(left, mid, number);
    }
}

template <typename Container> size_t PmergeMe<Container>::jacobsFormula(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsFormula(n - 1) + (2 * jacobsFormula(n - 2));
}

template <typename T> void PmergeMe<T>::startTimer()
{
    startTime = clock();
}

template <typename T> void PmergeMe<T>::endTimer()
{
    endTime = clock();
}

template <typename T> void PmergeMe<T>::showExecutionTime(const std::string &name, const std::string &container)
{
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    std::cout << "Execution time for " << name << " with " << getSize() << " elements in " << container << ": "
              << std::fixed << std::setprecision(6) << executionTime * 1000000 << " microseconds" << std::endl;
}

template <typename T> PmergeMe<T>::~PmergeMe() {}

template <typename T> PmergeMe<T>::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

template <typename T> const PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe<T>& copy)
{
    if (this != &copy)
    {
        // Logic for copying
    }
    return *this;
}

