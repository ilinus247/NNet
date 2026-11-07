//
// Created by Isaac Linus on 11/6/26.
//

#ifndef NNET_NNET_H
#define NNET_NNET_H
#include <vector>
#include "Layer.h"

class NNet {
    std::vector<Layer> layers;

public:
    NNet() = default;
    NNet(const std::vector<Layer> &_layers);

    DoubleMatrix forward(const DoubleMatrix &input);
    DoubleMatrix backward(const DoubleMatrix &grad, double learningRate);
};


#endif //NNET_NNET_H
