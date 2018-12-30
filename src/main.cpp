#include <iostream>

#include "neural_network.h"
#include "random_generator.h"

int main() {
  std::cout << "Start" << std::endl;

  LowScript translatorCode({LowNeuronParameters{Point{2.0, 2.0}, Point{2.0, 2.0}, 2.0, -1.2, 0.5}});

  NeuronMap translatorNeuronMap(translatorCode);

  ActivationMap activationMap({ActivationPoint{Point{2.0, 2.0}, 1.2}});

  NeuralNetwork translatorNN(translatorNeuronMap, activationMap);

  activationMap.printActivationMap();

  for (size_t i = 0; i < 4; i++) {
    translatorNN.doOneIteration();
    translatorNN.addRandomActivation({1.0, 0.0});
    activationMap.printActivationMap();
  }
}