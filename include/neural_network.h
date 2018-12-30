#pragma once

#include "activation_map.h"
#include "neuron_map.h"
#include "random_generator.h"

class NeuralNetwork {
 public:
  NeuralNetwork(NeuronMap &neuronMap, ActivationMap &activationMap);

  void doOneIteration();
  void addRandomActivation(const Point & point);
  void addActivationPoints(const HighNeuronParameters & parameters);

  HighNeuronParameters getHighNeuronParameters() const;
  LowNeuronParameters getLowNeuronParameters() const;
  
 private:
  NeuronMap &mNeuronMap;
  ActivationMap &mActivationMap;
  RandomGenerator mRandomGenerator;

};
