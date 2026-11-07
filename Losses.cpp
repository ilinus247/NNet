//
// Created by Isaac Linus on 11/6/26.
//

#include "DoubleMatrix.h"

static double mse(const DoubleMatrix &target, const DoubleMatrix &pred) {
    if (target.rows() != pred.rows() || target.cols() != pred.cols()) {
        throw std::runtime_error("matrix size mismatch in MSE");
    }
    DoubleMatrix error = (target - pred);
    error = error.hadamard(error);
    return error.elementSum()/(target.rows()*target.cols());
}

static DoubleMatrix mseGradient(const DoubleMatrix& target,
                                const DoubleMatrix& pred) {
    if (target.rows() != pred.rows() || target.cols() != pred.cols()) {
        throw std::runtime_error("Matrix size mismatch in MSE gradient");
    }

    return (pred - target) * (2.0 / (target.rows() * target.cols()));
}