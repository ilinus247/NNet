//
// Created by Isaac Linus on 11/6/26.
//

#pragma once
#include <cmath>

static double relu(const double x) {
    return x > 0 ? x : 0;
}

static double reluDerivative(const double x) {
    return x > 0 ? 1.0 : 0.0;
}

static double sigmoid(const double x) {
    return 1 / (1 + std::exp(-x));
}

static double sigmoidDerivative(const double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}