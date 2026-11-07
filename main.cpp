#include <iostream>

#include "NNet.h"
#include "Activations.h"
#include "Dataset.h"
#include "Losses.h"
#include "Trainer.h"
#include "XORDataset.h"

int main() {
    NNet net = NNet({
        Layer(2, 4, relu, reluDerivative),
        Layer(4, 4, relu, reluDerivative),
        Layer(4, 1, sigmoid, sigmoidDerivative),
    });
    Dataset* dataset = new XORDataset();
    Trainer t = Trainer(net, *dataset, mse, mseGradient);
    t.train(10000, 0.001);
}