#pragma once

#include <vector>

#include "neuron.h"

class NeuronMap {
 public:
  NeuronMap();
  NeuronMap(const std::vector<Neuron> &map);
  NeuronMap(const LowScript &script);

  const std::vector<Neuron> &getNeuronMap() const;

 private:
  std::vector<Neuron> mNeuronMap;
};
