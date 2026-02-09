#pragma once

#include <vector>

class Node {
    private:
        int input_size;
        std::vector<double> weights;
        int bias;
    public:
        double output;

        Node();

        void setWeights(int num_weights);
        double getOutput(std::vector<double>& inputs);
};