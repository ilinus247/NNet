//
// Created by Isaac Linus on 11/6/26.
//

#include "XORDataset.h"
#include <algorithm>
#include <random>

XORDataset::XORDataset() {
    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            DoubleMatrix input(1, 2);
            DoubleMatrix target(1, 1);

            input(0, 0) = a;
            input(0, 1) = b;
            target(0, 0) = a ^ b;

            data.emplace_back(input, target);
        }
    }
}

std::pair<DoubleMatrix, DoubleMatrix> XORDataset::next() {
    done = false;

    auto sample = data[position];
    ++position;

    if (position >= static_cast<int>(data.size())) {
        position = 0;
        done = true;
    }

    return sample;
}

bool XORDataset::allDone() const {
    return done;
}

void XORDataset::shuffle() {
    static std::mt19937 rng(std::random_device{}());
    std::shuffle(data.begin(), data.end(), rng);
}

bool XORDataset::supportsShuffle() const {
    return true;
}
