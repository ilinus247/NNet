//
// Created by Isaac Linus on 11/6/26.
//

#include "NNet.h"
#include <ranges>
#include <vector>

NNet::NNet(const std::vector<Layer> &_layers) {
    layers = _layers;
}

DoubleMatrix NNet::forward(const DoubleMatrix &input) {
    DoubleMatrix result = input;
    for (auto &layer : layers) {
        result = layer.forward(result);
    }
    return result;
}

DoubleMatrix NNet::backward(const DoubleMatrix &grad, double learningRate) {
    DoubleMatrix result = grad;

    for (auto & layer : std::views::reverse(layers)) {
        result = layer.backward(result, learningRate);
    }

    return result;
}