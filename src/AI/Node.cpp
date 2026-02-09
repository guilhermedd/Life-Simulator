#include "Node.hpp"

#include <random>
#include <chrono>

#include <iostream>

Node::Node() {
    bias = 0;
}

void Node::setWeights(int num_weights) {
    // Configura o gerador de números aleatórios (uma única vez para performance)
    static std::random_device rd;  
    static std::mt19937 gen(rd()); 

    // Define o intervalo: de -1.0 até 1.0
    std::uniform_real_distribution<> dis(-1.0, 1.0); 

    for (int i = 0; i < num_weights; i++) {
        // Gera um número aleatório e adiciona
        weights.push_back(dis(gen));
    }
}

double Node::getOutput(std::vector<double> inputs) {
    if (weights.empty()) {
        setWeights(inputs.size());
    }

    double this_output = bias;
    for (int i = 0; i < inputs.size(); i++) {
        this_output += inputs[i] * weights[i];
    }

    return this_output;
}