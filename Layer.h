//
// Created by Isaac Linus on 11/6/26.
//

#ifndef NNET_LAYER_H
#define NNET_LAYER_H
#include "DoubleMatrix.h"


class Layer {
    DoubleMatrix weights;
    DoubleMatrix bias;
    double (*activation)(double);
    double (*activationDerivative)(double);
    DoubleMatrix latestInput;
    DoubleMatrix latestPreOutput;
    DoubleMatrix latestOutput;

public:
    Layer(int _input_size, int _output_size, double (*_activation)(double), double (*_activationDerivative)(double));
    DoubleMatrix forward(const DoubleMatrix &input);
    DoubleMatrix backward(const DoubleMatrix &grad, double learningRate);

};


#endif //NNET_LAYER_H
