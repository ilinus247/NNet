//
// Created by Isaac Linus on 11/6/26.
//

#ifndef NNET_XORDATASET_H
#define NNET_XORDATASET_H
#include "Dataset.h"
#include <vector>
#include <utility>

class XORDataset : public Dataset {
    std::vector<std::pair<DoubleMatrix, DoubleMatrix> > data;
    int position = 0;
    bool done = false;

public:
    XORDataset();

    std::pair<DoubleMatrix, DoubleMatrix> next() override;

    bool allDone() const override;

    void shuffle() override;

    bool supportsShuffle() const override;
};


#endif //NNET_XORDATASET_H
