#pragma once

#include "activation_map.h"
#include "neuron_map.h"

class NeuralNetwork {
 public:
  NeuralNetwork(NeuronMap &neuronMap, ActivationMap &activationMap);

  void doOneIteration();

 private:
  NeuronMap &mNeuronMap;
  ActivationMap &mActivationMap;
};
