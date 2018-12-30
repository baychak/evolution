#pragma once

#include "activation_map.h"
#include "neuron_script.h"
#include "point.h"

class Neuron {
 public:
  Neuron();
  Neuron(Point in, Point out, double amplification, double sensitivity,
         double bias);
  Neuron(const NeuronParameters &parameters);

  ActivationPoint operator()(const ActivationMap &activationMap) const;

 private:
  const NeuronParameters mParameters;

  double activationFunction(double x) const;
};
