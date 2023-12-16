#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array 
{
    private:
        T *_arr;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        const Array& operator=(const Array &src);
        T& operator[](unsigned int index);
        ~Array();
        unsigned int size() const;
};

#endif
