#include "neuron.h"

#include <cmath>
#include <iostream>

Neuron::Neuron()
    : mParameters(
          NeuronParameters{Point{0.0, 0.0}, Point{0.0, 0.0}, 0.0, 1.0, 0.0}) {}

Neuron::Neuron(Point in, Point out, double amplification, double sensitivity,
               double bias)
    : mParameters(NeuronParameters{in, out, amplification, sensitivity, bias}) {
}

Neuron::Neuron(const NeuronParameters &parameters) : mParameters(parameters) {}

double Neuron::activationFunction(double x) const {
  x = mParameters.sensitivity * (x - mParameters.bias);
  double absA = std::abs(mParameters.amplification);
  if (x > absA) {
    return absA;
  } else if (x < -absA) {
    return -absA;
  } else {
    return x;
  };
}

ActivationPoint Neuron::operator()(const ActivationMap &activationMap) const {
  return ActivationPoint{
      mParameters.out,
      activationFunction(activationMap.getActivation(mParameters.in))};
}
