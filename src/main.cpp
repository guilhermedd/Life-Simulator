#include "AI/Brain.hpp"

#include <iostream>
#include <vector>
#include <algorithm> // Necessário para achar o maior elemento
#include <cmath>

using namespace std;

// Função auxiliar que simula um Softmax com saída binária (One-Hot)
// Transforma [2.5, 9.1, 1.2] em [0, 1, 0]
vector<double> softmax_binary(vector<double> raw_values) {
    vector<double> result(raw_values.size(), 0.0); // Cria vetor de zeros

    // 1. Acha o índice do maior valor (ArgMax)
    int max_index = 0;
    double max_value = raw_values[0];

    for (size_t i = 1; i < raw_values.size(); i++) {
        if (raw_values[i] > max_value) {
            max_value = raw_values[i];
            max_index = i;
        }
    }

    // 2. Define o vencedor como 1
    result[max_index] = 1.0;
    
    return result;
}

int main() {
    Brain brain;
    vector<double> inputs = {1.0, 2}; // Inputs devem ser double

    // Configuração da rede
    brain.add_layer(3); // Entrada
    brain.add_layer(5); // Entrada
    brain.add_layer(3); // Entrada
    brain.add_layer(2); // Entrada

    // 1. Pega os valores brutos (Raw Logits) do cérebro
    vector<double> raw_output = brain.get_output(inputs);
    cout << "Output: ";
    for (auto val : raw_output) {
        cout << val << ", ";
    }
    cout << endl;

    // 2. Passa pelo "Filtro Decisor" (Softmax Binário)
    vector<double> decision = softmax_binary(raw_output);

    // Mostra o resultado
    cout << "Decisão Final: ";
    for (auto val : decision) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}