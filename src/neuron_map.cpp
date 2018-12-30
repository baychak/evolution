#include "neuron_map.h"

NeuronMap::NeuronMap() {}

NeuronMap::NeuronMap(const std::vector<Neuron> &map) : mNeuronMap(map) {}

const std::vector<Neuron> &NeuronMap::getNeuronMap() const {
  return mNeuronMap;
}
