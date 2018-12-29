#pragma once

#include "neuron_map.h"
#include "activation_map.h"

class NeuralNetwork
{
  public:
    NeuralNetwork(NeuronMap &neuronMap, ActivationMap &activationMap);

    void doOneIteration();

  private:
    NeuronMap &mNeuronMap;
    ActivationMap &mActivationMap;
};
