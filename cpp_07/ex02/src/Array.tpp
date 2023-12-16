#include "../includes/Array.hpp"

template <class T>
Array<T>::Array() : _size(0)
{
    this->_arr = new T[0];
};

template <class T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->_arr = new T[n];
};

template <class T> 
Array<T>::Array(const Array& other)
{
    this->_size = other.size();
    this->_arr = new T[this->_size];
    for(unsigned int i = 0; i < this->_size; i++)
        this->_arr[i] = other._arr[i];
};

template <class T>
const Array<T> &Array<T>::operator=(const Array &src)
{
    if(this != &src)
    {
        delete [] _arr;
        _size = src._size;
        _arr = new T[_size];
        for(unsigned int i = 0; i < _size; i++)
            _arr[i] = src._arr[i];
    }
    return (*this);
};

template <class T>
T& Array<T>::operator[](unsigned int index)
{
    if(index >= 0 && index < _size)
        return _arr[index];
    throw(std::out_of_range("Array index out of bounds"));
}

template <class T>
Array<T>::~Array()
{
    delete [] this->_arr;
}

template <class T>
unsigned int Array<T>::size() const
{
    return this->_size;
}