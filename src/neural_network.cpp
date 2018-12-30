#include "neural_network.h"

#include <iostream>

NeuralNetwork::NeuralNetwork(NeuronMap &neuronMap, ActivationMap &activationMap)
    : mNeuronMap(neuronMap),
      mActivationMap(activationMap),
      mRandomGenerator(0.0, 1.0) {}

void NeuralNetwork::doOneIteration() {
  ActivationMap newMap;

  for (Neuron neuron : mNeuronMap.getNeuronMap()) {
    newMap.addActivationPoint(neuron(mActivationMap));
  }

  mActivationMap = newMap;
}

void NeuralNetwork::addRandomActivation(const Point &point) {
  mActivationMap.addActivationPoint(
      ActivationPoint{point, mRandomGenerator.getNormalValue()});
}

void NeuralNetwork::addActivationPoints(
    const HighNeuronParameters &parameters) {
  mActivationMap.addActivationPoint({{0.0, 0.0}, parameters.in.x});
  mActivationMap.addActivationPoint({{0.0, 2.0}, parameters.in.y});
  mActivationMap.addActivationPoint({{0.0, 4.0}, parameters.out.x});
  mActivationMap.addActivationPoint({{0.0, 6.0}, parameters.out.y});
  mActivationMap.addActivationPoint({{0.0, 8.0}, parameters.amplification});
  mActivationMap.addActivationPoint({{0.0, 10.0}, parameters.sensitivity});
  mActivationMap.addActivationPoint({{0.0, 12.0}, parameters.bias});
}

HighNeuronParameters NeuralNetwork::getHighNeuronParameters() const {
  return HighNeuronParameters{
      {mActivationMap.getActivation({10.0, 0.0}),
       mActivationMap.getActivation({10.0, 2.0})},
      {mActivationMap.getActivation({10.0, 4.0}),
       mActivationMap.getActivation({10.0, 6.0})},
      mActivationMap.getActivation({10.0, 8.0}),
      mActivationMap.getActivation({10.0, 10.0}),
      mActivationMap.getActivation({10.0, 12.0}),
  };
}

LowNeuronParameters NeuralNetwork::getLowNeuronParameters() const {
  return LowNeuronParameters{
      {mActivationMap.getActivation({10.0, 0.0}),
       mActivationMap.getActivation({10.0, 2.0})},
      {mActivationMap.getActivation({10.0, 4.0}),
       mActivationMap.getActivation({10.0, 6.0})},
      mActivationMap.getActivation({10.0, 8.0}),
      mActivationMap.getActivation({10.0, 10.0}),
      mActivationMap.getActivation({10.0, 12.0}),
  };
}
