//
// Created by Isaac Linus on 11/6/26.
//

#ifndef NNET_TRAINER_H
#define NNET_TRAINER_H
#include "Dataset.h"
#include "NNet.h"


class Trainer {
    NNet net;
    Dataset *dataset;
    double (*lossFn)(const DoubleMatrix&, const DoubleMatrix&);
    DoubleMatrix (*lossGradFn)(const DoubleMatrix&, const DoubleMatrix&);

    double train_step(double learningRate);

public:
    Trainer(const NNet &_net,
        Dataset &_dataset,
        double (*_lossFn)(const DoubleMatrix&, const DoubleMatrix&),
        DoubleMatrix (*_lossGradFn)(const DoubleMatrix&, const DoubleMatrix&));

    void train(int epochs, double learningRate);

    void train(int epochs, double (*learningRate)(int));

    NNet &getNet() {
        return net;
    }
};


#endif //NNET_TRAINER_H
