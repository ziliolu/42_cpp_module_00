#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <numbers>...\n";
        return 1;
    }

    PmergeMe<std::vector<int> > vectorSorter(argc, argv);
    PmergeMe<std::deque<int> > dequeSorter(argc, argv);

    std::cout << "Original Vector:\n";
    vectorSorter.printMain();
    std::cout << "Original Deque:\n";
    dequeSorter.printMain();

    vectorSorter.mergeSort(0, vectorSorter.getSize() - 1);
    dequeSorter.mergeSort(0, dequeSorter.getSize() - 1);

    vectorSorter.insertIntoSortedList();
    dequeSorter.insertIntoSortedList();

    std::cout << "\nSorted Vector:\n";
    vectorSorter.printContainer(vectorSorter.getMain());
    std::cout << "Sorted Deque:\n";
    dequeSorter.printContainer(dequeSorter.getMain());

    vectorSorter.showExecutionTime("Merge Sort", "Vector");
    dequeSorter.showExecutionTime("Merge Sort",  "Deque");

    return 0;
}
