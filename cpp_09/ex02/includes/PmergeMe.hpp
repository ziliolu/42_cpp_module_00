#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <deque>

template <typename T>
class PmergeMe {
private:
    T main;        // Container principal (onde ocorre a ordenação)
    T pending;     // Container auxiliar (pendente para inserção)

    clock_t startTime;
    clock_t endTime;

    void startTimer();
    void endTimer();

    void groupElements(int argc, char **argv);
    void merge(int left, int mid, int right);
    void binaryInsert(int left, int right, int number);
    size_t jacobsFormula(size_t n);

public:
    PmergeMe(int argc, char **argv);             // Construtor
    ~PmergeMe();                                // Destruidor
    PmergeMe(const PmergeMe &copy);              // Construtor de cópia
    const PmergeMe& operator=(const PmergeMe &copy); // Sobrecarga do operador de atribuição

    int getSize() const;                        // Retorna o tamanho do container principal
    T getMain() const;                          // Retorna o container principal
    T getPending() const;                       // Retorna o container auxiliar

    void printContainer(T container);           // Imprime qualquer container
    void printMain();                           // Imprime o container principal
    void printPending();                        // Imprime o container auxiliar
    void mergeSort(int left, int right);
    void showExecutionTime(const std::string &name, const std::string &container); // Exibe o tempo de execução
    void insertIntoSortedList();
};

#include "../src/PmergeMe.tpp"

#endif
