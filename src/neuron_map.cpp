#include "neuron_map.h"

NeuronMap::NeuronMap() {}

NeuronMap::NeuronMap(const std::vector<Neuron> &map) : mNeuronMap(map) {}

NeuronMap::NeuronMap(const LowScript &script) {
    
    for(const LowNeuronParameters parameters : script)
    {
        mNeuronMap.emplace_back(parameters);
    }
}

const std::vector<Neuron> &NeuronMap::getNeuronMap() const {
  return mNeuronMap;
}
