#pragma once

#include "activation_map.h"
#include "point.h"

class Neuron {
public:
    Neuron();
    Neuron(Point in, Point out, double amplification, double sensitivity, double bias);

    ActivationPoint operator()(const ActivationMap & activationMap) const;

private:
    const Point in;
    const Point out;
    const double amplification;
    const double sensitivity;
    const double bias;

    double activationFunction(double x) const;
};
