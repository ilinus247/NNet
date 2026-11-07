//
// Created by Isaac Linus on 11/6/26.
//

#ifndef NNET_DATASET_H
#define NNET_DATASET_H
#include "DoubleMatrix.h"


class Dataset {
public:
    virtual ~Dataset() = default;

    virtual std::pair<DoubleMatrix, DoubleMatrix> next() = 0;
    virtual bool allDone() const = 0;

    virtual void shuffle() {
        throw std::runtime_error("This dataset does not support shuffle");
    }

    virtual bool supportsShuffle() const {
        return false;
    }
};


#endif //NNET_DATASET_H
