#pragma once

#include "neural_network.h"

class Replicator {
 public:
  Replicator(const LowScript &replicatorCode);

  HighScript operator()(const HighScript &code);

 private:
  NeuronMap mNeuronMap;
  ActivationMap mActivationMap;
  NeuralNetwork mNN;
};
