//
// Created by Isaac Linus on 11/6/26.
//

#include <cmath>

static double relu(const double x) {
    return x > 0 ? x : 0;
}

static double sigmoid(const double x) {
    return 1 / (1 + std::exp(-x));
}