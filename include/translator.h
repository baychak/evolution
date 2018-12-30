#pragma once

#include "neural_network.h"

class Translator {
 public:
  Translator(const LowScript &tranlatorCode);

  LowScript operator()(const HighScript &code);

 private:
  NeuralNetwork mNN;
  NeuronMap mNeuronMap;
  ActivationMap mActivationMap;
};
