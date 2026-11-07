cmake_minimum_required(VERSION 4.3)
project(NNet)

set(CMAKE_CXX_STANDARD 20)

add_executable(NNet main.cpp
        DoubleMatrix.cpp
        DoubleMatrix.h
        Activations.h
        Layer.cpp
        Layer.h
        NNet.cpp
        NNet.h
        Losses.h
        Dataset.h
        XORDataset.cpp
        XORDataset.h
        Trainer.cpp
        Trainer.h)
