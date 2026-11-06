//
// Created by Isaac Linus on 11/6/26.
//

#include "DoubleMatrix.h"
#include <stdexcept>


DoubleMatrix::DoubleMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }
    m = rows;
    n = cols;
    mat = std::vector<double>(m * n);
}


DoubleMatrix& DoubleMatrix::operator+=(const DoubleMatrix& other) {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Incompatible matrix dimensions");
    }
    for (int i = 0; i < m * n; i++) {
        mat[i] += other.mat[i];
    }
    return *this;
}

DoubleMatrix DoubleMatrix::operator+(const DoubleMatrix &other) const {
    DoubleMatrix result = *this;
    result += other;
    return result;
}

DoubleMatrix& DoubleMatrix::operator-=(const DoubleMatrix& other) {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Incompatible matrix dimensions");
    }
    for (int i = 0; i < m * n; i++) {
        mat[i] -= other.mat[i];
    }

    return *this;
}

DoubleMatrix& DoubleMatrix::operator*=(double scalar) {
    for (int i = 0; i < m * n; i++) {
        mat[i] *= scalar;
    }
    return *this;
}

DoubleMatrix DoubleMatrix::operator*(const double scalar) const {
    DoubleMatrix result = *this;
    result *= scalar;
    return result;
}

DoubleMatrix DoubleMatrix::operator*(const DoubleMatrix &other) const {
    if (n != other.m) {
        throw std::invalid_argument("Incompatible matrix dimensions");
    }

    DoubleMatrix result(m, other.n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < other.n; j++) {
            for (int k = 0; k < n; k++) {
                result(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }

    return result;
}

DoubleMatrix DoubleMatrix::operator-(const DoubleMatrix& other) const {
    DoubleMatrix result = *this;
    result -= other;
    return result;
}

const double &DoubleMatrix::operator()(const int i, const int j) const {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        throw std::out_of_range("Matrix index out of bounds");
    }
    return mat[n * i + j];
}

double &DoubleMatrix::operator()(const int i, const int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        throw std::out_of_range("Matrix index out of bounds");
    }
    return mat[n * i + j];
}

int DoubleMatrix::rows() const {
    return m;
}

int DoubleMatrix::cols() const {
    return n;
}

DoubleMatrix DoubleMatrix::transpose() const {
    DoubleMatrix result(n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

DoubleMatrix DoubleMatrix::hadamard(const DoubleMatrix& other) const {
    if (m != other.m || n != other.n) {
        throw std::invalid_argument("Incompatible matrix dimensions");
    }
    DoubleMatrix result(m, n);
    for (int i = 0; i < m * n; i++) {
        result.mat[i] = mat[i] * other.mat[i];
    }
    return result;
}

DoubleMatrix DoubleMatrix::apply(double (*activation)(double)) const {
    DoubleMatrix result = *this;

    for (int i = 0; i < m * n; i++) {
        result.mat[i] = activation(result.mat[i]);
    }

    return result;
}
