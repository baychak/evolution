#include "neuron_map.h"

NeuronMap::NeuronMap() : 
    mNeuronMap{Neuron{}, Neuron{}}
{}

const std::vector<Neuron> & NeuronMap::getNeuronMap() const {
    return mNeuronMap;
}


