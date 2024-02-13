/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD12-tanguy.bellicha
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <exception>
#include <string>
#include <functional>

template <typename T, size_t Size>
class Array {
    public:
        Array() {
            this->_size = Size;
            this->_array = new T[Size];
        }
        ~Array() {
            //delete this->_array;
        }

        T& operator[](size_t index)
        {
            if (index >= this->_size)
                throw std::out_of_range("Out of range");
            return (this->_array[index]);
        }
        const T& operator[](size_t index) const
        {
            if (index >= this->_size)
                throw std::out_of_range("Out of range");
            return (this->_array[index]);
        }

        std::size_t size() const {
            return (this->_size);
        }

        void forEach(const std::function <void(const T&)>& task) const {
            for (size_t index = 0; index < this->_size; index++)
                task(this->_array[index]);
        }

        template <typename U>
        Array<U, Size> convert(const std::function <U(const T&)>& converter) const {
            Array<U, Size> tmp;

            for (size_t index = 0; index < this->_size; index++)
                tmp._array[index] = converter(this->_array[index]);
            return (tmp);
        }

        size_t _size;
        T* _array;
    protected:
    private:
};

template <typename T, size_t Size>
std::ostream& operator<<(std::ostream& os, const Array<T, Size>& array) {
    os << "[";
    for (size_t index = 0; index < array.size(); index++) {
        if (index + 1 != array.size())
            os << array[index] << ", ";
        else
            os << array[index];
    }
    os << "]";
    return (os);
}

#endif /* !ARRAY_HPP_ */
