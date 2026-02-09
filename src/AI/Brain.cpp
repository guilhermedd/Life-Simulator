#include "Brain.hpp"

#include <iostream>

Brain::Brain(){
    num_layers = 0;
}


void Brain::add_layer(int num_nodes_this_layer){
    num_layers++;
    num_nodes.push_back(num_nodes_this_layer);
    layers.push_back(std::vector<Node>(num_nodes_this_layer));
}

void print_vector(std::vector<double> vector) {
    for (auto &value : vector) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}

std::vector<double> Brain::get_output(std::vector<double> inputs) {
    auto next_inputs = inputs;
    for (int cur_layer = 0; cur_layer < num_layers; cur_layer++) {
        std::vector<double> outputs;

        for (auto &neuron : layers[cur_layer]) {
            outputs.push_back(neuron.getOutput(next_inputs));
        }
        next_inputs = outputs;
    }
    return next_inputs;
}