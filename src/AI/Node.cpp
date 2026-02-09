#include "Node.hpp"

#include <random>
#include <chrono>

#include <iostream>

Node::Node() {
    bias = 0;
}

void Node::setWeights(int num_weights) {
    static std::random_device rd;  
    static std::mt19937 gen(rd()); 

    weights.clear();
    weights.reserve(num_weights);

    std::uniform_real_distribution<> dis(-1.0, 1.0); 
    
    bias = dis(gen);

    for (int i = 0; i < num_weights; i++) {
        weights.push_back(dis(gen));
    }
}

double Node::getOutput(std::vector<double>& inputs) {
    if (weights.empty()) {
        setWeights(inputs.size());
    }

    double this_output = bias;
    for (int i = 0; i < int(inputs.size()); i++) {
        this_output += inputs[i] * weights[i];
    }

    return this_output <= 0 ? 0 : this_output ;
}