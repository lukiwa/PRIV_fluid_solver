//
// Created by Lukasz on 01.06.2020.
//

#pragma once

#include <algorithm>

template<typename T>
class Array2D {
    int _size;
    T *array;
public:
    explicit Array2D(int size) :
            _size(size) {
        array = new T[size * size];
    }

    virtual ~Array2D() {
        delete[] array;
    }

    Array2D(const Array2D &other) {
        _size = other._size;
        std::copy(other.array, other.array + other._size, array);
    }

    Array2D &operator=(const Array2D &other) {
        if (&other != this) {
            _size = other._size;
            std::copy(other.array, other.array + other._size, array);
        }
        return *this;
    }

    int GetSize() {
        return _size;
    }


    T &operator()(int x, int y) const {
        return array[x + y * _size];
    }

    T &operator()(int x, int y) {
        return array[x + y * _size];
    }

    T &at(int x, int y) const {
        if (x >= _size) { throw std::out_of_range("Array out of bound"); }
        if (y >= _size) { throw std::out_of_range("Array out of bound"); }
        return array[x + y * _size];
    }

    T &at(int x, int y) {
        if (x >= _size) { throw std::out_of_range("Array out of bound"); }
        if (y >= _size) { throw std::out_of_range("Array out of bound"); }
        return array[x + y * _size];
    }

};





