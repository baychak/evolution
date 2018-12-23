#include "neural_network.h"

#include <iostream>

NeuralNetwork::NeuralNetwork(NeuronMap & neuronMap, ActivationMap & activationMap):
    mNeuronMap(neuronMap),
    mActivationMap(activationMap)
{}

void NeuralNetwork::doOneIteration() {
    
    std::vector<ActivationPoint> newMap;

    for(Neuron neuron : mNeuronMap.getNeuronMap())
    {
        newMap.emplace_back(neuron(mActivationMap.getActivationMap()));
    }

    mActivationMap.setActivationMap(newMap);
}
