/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD15-jack.goodall
** File description:
** ex05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

#include <exception>
#include <iostream>

template<typename T>
class array {
    public:
        array() : _size(0), _arr(new T[0]) {};
        array(unsigned int size) : _size(size), _arr(new T[size]) {};
        array(const array&) = default;
        array &operator=(const array &) = default;
        ~array() {
            delete[] _arr;
        };

        T &operator[](unsigned int idx) {
            if (idx >= _size) {
                T *tmp = new T[idx + 1];
                for (unsigned int i = 0; i < _size; i++)
                    tmp[i] = _arr[i];
                delete[] _arr;
                _arr = tmp;
                _size = idx + 1;
            }
            return _arr[idx];
        };

        T &operator[](unsigned int idx) const {
            if (idx >= _size) {
                throw std::exception();
            }
            return _arr[idx];
        };

        unsigned int size() const { return _size; }

        void dump() const {
            std::cout << "[";
            for (unsigned int i = 0; i < _size; i++) {
                if (i) std::cout << ", ";
                std::cout << _arr[i];
            }
            std::cout << "]" << std::endl;
        }

        template<typename U>
        array<U> &convertTo(U (*func)(T const &)) const {
            array<U> *new_arr = new array<U>(_size);

            for (unsigned int i = 0; i < _size; i++) {
                (*new_arr)[i] = func(_arr[i]);
            }
            return *new_arr;
        }

    private:
        unsigned int _size;
        T *_arr;
};

template<> void array<bool>::dump() const
{
    std::cout << "[";
    for (unsigned int i = 0; i < _size; i++) {
        if (i) std::cout << ", ";
        std::cout << ((_arr[i]) ? "true" : "false");
    }
    std::cout << "]" << std::endl;
}

#endif /* !EX05_HPP_ */
