#pragma once

#include "activation_map.h"
#include "point.h"

class Neuron {
public:
    Neuron();
    Neuron(Point in, Point out, double amplification, double bias, double sensitivity);

    ActivationPoint operator()(const std::vector<ActivationPoint> & activationMap) const;

private:
    const Point in;
    const Point out;
    const double amplification;
    const double bias;
    const double sensitivity;

    double getActivation(const std::vector<ActivationPoint> & activationMap) const;
};
