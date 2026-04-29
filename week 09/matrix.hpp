#ifndef __MATRIX_H__
#define __MATRIX_H__
#include "vector.hpp"

template<typename T>
class Matrix{
    Vector<Vector<T>> matrix;

    public:
    Vector<T>& operator[](const size_t& index) {
        return matrix[index];
    }

    void append(const Vector<T>& row) {
        matrix.append(row);
    }

    size_t lenght() const {
        return matrix.lenght();
    }
};

#endif