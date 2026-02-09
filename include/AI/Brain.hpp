#pragma once

#include "Node.hpp"

#include <vector>

class Brain {
    private:
        int num_layers;
        std::vector<int> num_nodes;
        std::vector<std::vector<Node>> layers;
    public:
        Brain();

        void add_layer(int num_nodes);
        std::vector<double> get_output(std::vector<double> inputs);
};

