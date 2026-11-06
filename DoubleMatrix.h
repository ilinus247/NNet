//
// Created by Isaac Linus on 11/6/26.
//

#ifndef NNET_MATRIX_H
#define NNET_MATRIX_H
#include <vector>

class DoubleMatrix {
    std::vector<double> mat;
    int m = 0;
    int n = 0;
public:
    DoubleMatrix() = default;
    DoubleMatrix(int rows, int cols);

    DoubleMatrix operator+(const DoubleMatrix& other) const;
    DoubleMatrix operator*(const DoubleMatrix& other) const;
    DoubleMatrix operator*(double scalar) const;
    DoubleMatrix operator-(const DoubleMatrix& other) const;
    DoubleMatrix& operator+=(const DoubleMatrix& other);
    DoubleMatrix& operator-=(const DoubleMatrix& other);
    DoubleMatrix& operator*=(double scalar);
    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;
    int rows() const;
    int cols() const;

    DoubleMatrix transpose() const;
    DoubleMatrix hadamard(const DoubleMatrix& other) const;
    DoubleMatrix apply(double (*activation)(double)) const;
};


#endif //NNET_MATRIX_H
