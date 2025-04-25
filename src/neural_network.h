//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_NEURALNETWORK_V2025_01_NEURAL_NETWORK_H
#define PROG3_UNIT2_NEURALNETWORK_V2025_01_NEURAL_NETWORK_H

#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <type_traits>

// Interfaz base genérica para capas
template<typename T>
class Layer {
public:
    virtual ~Layer() = default;
    virtual std::vector<T> forward(const std::vector<T>& input) = 0;
};

// Capa Dense: out[i] = in[i] * weight + bias
template<typename T>
class Dense : public Layer<T> {
    T weight;
    T bias;
public:
    Dense(T w, T b)
        : weight(w), bias(b) {}

    std::vector<T> forward(const std::vector<T>& input) override {
        std::vector<T> output;
        output.reserve(input.size());
        for (const auto& v : input) {
            output.push_back(v * weight + bias);
        }
        return output;
    }
};

// Capa ReLU: out[i] = max(0, in[i])
template<typename T>
class ReLU : public Layer<T> {
public:
    std::vector<T> forward(const std::vector<T>& input) override {
        std::vector<T> output;
        output.reserve(input.size());
        for (const auto& v : input) {
            output.push_back(v > T(0) ? v : T(0));
        }
        return output;
    }
};

// Capa Dropout: elimina posiciones pares, conserva índices 1,3,5,...
template<typename T>
class Dropout : public Layer<T> {
public:
    std::vector<T> forward(const std::vector<T>& input) override {
        std::vector<T> output;
        for (size_t i = 1; i < input.size(); i += 2) {
            output.push_back(input[i]);
        }
        return output;
    }
};

// Capa Softmax: distribución de probabilidad estable
template<typename T>
class Softmax : public Layer<T> {
public:
    std::vector<T> forward(const std::vector<T>& input) override {
        if (input.empty()) return {};
        T m = *std::max_element(input.begin(), input.end());
        std::vector<T> exps;
        exps.reserve(input.size());
        for (const auto& v : input) {
            exps.push_back(std::exp(v - m));
        }
        T sum = std::accumulate(exps.begin(), exps.end(), T(0));
        std::vector<T> output;
        output.reserve(exps.size());
        for (const auto& e : exps) {
            output.push_back(e / sum);
        }
        return output;
    }
};

// Clase neuronal genérica: comparte un único weight y bias en todas las capas Dense
// usando variadic templates y template-template parameters
template<
    typename T,
    template<typename> class... LayerTypes
>
class NeuralNetwork {
    std::vector<std::unique_ptr<Layer<T>>> layers;

    template<template<typename> class L>
    static std::unique_ptr<Layer<T>> make_layer(T weight, T bias) {
        if constexpr (std::is_same_v<L<T>, Dense<T>>) {
            return std::make_unique<Dense<T>>(weight, bias);
        } else {
            return std::make_unique<L<T>>();
        }
    }

public:
    // Constructor: recibe un único weight y bias para todas las capas Dense
    NeuralNetwork(T weight, T bias) {
        layers.reserve(sizeof...(LayerTypes));
        (layers.push_back(make_layer<LayerTypes>(weight, bias)), ...);
    }

    // Aplica secuencialmente forward() de cada capa
    std::vector<T> predict(const std::vector<T>& input) {
        std::vector<T> result = input;
        for (auto& layer : layers) {
            result = layer->forward(result);
        }
        return result;
    }
};


#endif //PROG3_UNIT2_NEURALNETWORK_V2025_01_NEURAL_NETWORK_H
