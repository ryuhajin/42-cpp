# ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;
public:
    Array();
    Array(unsigned int size);
    Array(const Array& other);
    virtual ~Array();

    Array& operator= (const Array& other);

    T& operator[] (unsigned int idx);
    const T& operator[] (unsigned int idx) const;

    unsigned int size() const;
};

template <typename T>
Array<T>::Array()
        :_array(NULL), _size(0)
{
    std::cout << "[constructor] Array" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size)
        :_array(new T[size]()), _size(size)
{
    std::cout << "[constructor] Array" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other)
        :_array(new T[other._size]), _size(other._size)
{
    for (size_t i = 0; i < _size; i++)
        this->_array[i] = other._array[i];

    std::cout << "[Copy constructor] Array" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
    std::cout << "[destructor] Array" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this == &other)
        return (*this);
    
    delete[] _array;

	this->_size = other._size;
    this->_array = new T[_size];

    for (size_t i = 0; i < _size; i++)
        this->_array[i] = other._array[i];

    std::cout << "[Copy operator=] Array" << std::endl;
    return (*this);
}

template <typename T>
T& Array<T>::operator[] (unsigned int idx)
{
    if (idx >= _size)
        throw std::out_of_range("Index out of range");

    return _array[idx];
}

template <typename T>
const T& Array<T>::operator[] (unsigned int idx) const
{
    if (idx >= _size)
        throw std::out_of_range("Index out of range");

    return _array[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

#endif