#include <iostream>

#include "neural_network.h"

int main() {
  std::cout << "Start" << std::endl;

  NeuronMap neuronMap(
      {NeuronParameters{Point{2.0, 2.0}, Point{2.0, 2.0}, 2.0, -1.2, 0.5}});

  ActivationMap activationMap({ActivationPoint{Point{2.0, 2.0}, 1.2}});

  NeuralNetwork NN(neuronMap, activationMap);

  activationMap.printActivationMap();

  for (size_t i = 0; i < 10; i++) {
    NN.doOneIteration();
    activationMap.printActivationMap();
  }
}