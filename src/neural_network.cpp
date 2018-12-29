#include "neural_network.h"

#include <iostream>

NeuralNetwork::NeuralNetwork(NeuronMap &neuronMap, ActivationMap &activationMap) : mNeuronMap(neuronMap),
                                                                                   mActivationMap(activationMap)
{
}

void NeuralNetwork::doOneIteration()
{

    ActivationMap newMap;

    for (Neuron neuron : mNeuronMap.getNeuronMap())
    {
        newMap.addActivationPoint(neuron(mActivationMap));
    }

    mActivationMap = newMap;
}
