#ifndef __MATRIX2_H__
#define __MATRIX2_H__
#include "vector.hpp"

template<typename T>
class Matrix2{
    Vector<Vector<T>> matrix;
    size_t columns; 

    public:
    Matrix2() {
        columns = 0;
    }

    Vector<T>& operator[](const size_t& index) {
        return matrix[index];
    }

    void append(const Vector<T>& row) {
        const size_t rowColumns = row.lenght();
        T defaultValue;

        matrix.append(row);
        size_t index = matrix.lenght() - 1;

        if (columns < rowColumns) {
            columns = rowColums;
            for (size_t i = 0; i < index; ++i) {
                while(matrix[i].lenght() < columns) {
                    matrix[i].append(defaultValue);
                }
            }
        } else {
            while(matrix[index].lenght() < columns) {
                matrix[index].append(defaultValue);
            }
        }
    }

    size_t lenght() const {
        return matrix.lenght();
    }
};

#endif