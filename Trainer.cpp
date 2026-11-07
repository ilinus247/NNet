//
// Created by Isaac Linus on 11/6/26.
//

#include "Trainer.h"

Trainer::Trainer(const NNet &_net,
                 Dataset &_dataset,
                 double (*_lossFn)(const DoubleMatrix&, const DoubleMatrix&),
                 DoubleMatrix (*_lossGradFn)(const DoubleMatrix&, const DoubleMatrix&)) {
    net = _net;
    dataset = &_dataset;
    lossFn = _lossFn;
    lossGradFn = _lossGradFn;
}

double Trainer::train_step(const double learningRate) {
    std::pair<DoubleMatrix, DoubleMatrix> data = dataset->next();
    const DoubleMatrix pred = net.forward(data.first);
    const double loss = lossFn(data.second, pred);
    net.backward(lossGradFn(data.second, pred), learningRate);
    return loss;
}

void Trainer::train(const int epochs, double (*learningRate)(int)) {
    for (int i = 0; i < epochs; i++) {
        const double _learningRate = learningRate(i);
        do {
            train_step(_learningRate);
        } while (!dataset->allDone());

        if (dataset->supportsShuffle()) {
            dataset->shuffle();
        }
    }
}

void Trainer::train(const int epochs, const double learningRate) {
    for (int i = 0; i < epochs; i++) {
        do {
            train_step(learningRate);
        } while (!dataset->allDone());

        if (dataset->supportsShuffle()) {
            dataset->shuffle();
        }
    }
}
