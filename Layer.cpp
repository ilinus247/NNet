//
// Created by Isaac Linus on 11/6/26.
//

#include "Layer.h"
#include <random>
#include <cmath>

Layer::Layer(const int _input_size, const int _output_size, double (*_activation)(double),
             double (*_activationDerivative)(double)) {
    weights = DoubleMatrix(_input_size, _output_size);
    bias = DoubleMatrix(1, _output_size);
    activation = _activation;
    activationDerivative = _activationDerivative;

    std::mt19937 rng(std::random_device{}());

    const double stddev = std::sqrt(2.0 / _input_size);
    std::normal_distribution dist(0.0, stddev);

    for (int i = 0; i < _input_size; i++) {
        for (int j = 0; j < _output_size; j++) {
            weights(i, j) = dist(rng);
        }
    }
}

DoubleMatrix Layer::forward(const DoubleMatrix &input) {
    latestInput = input;
    latestPreOutput = (input * weights + bias);
    latestOutput = latestPreOutput.apply(activation);
    return latestOutput;
}

DoubleMatrix Layer::backward(const DoubleMatrix &grad, const double learningRate) {
    DoubleMatrix delta = grad.hadamard(latestPreOutput.apply(activationDerivative));

    DoubleMatrix weightGradient = latestInput.transpose() * delta;

    DoubleMatrix inputGradient = delta * weights.transpose();
    weights -= weightGradient * learningRate;
    bias -= delta * learningRate;
    return inputGradient;
}

