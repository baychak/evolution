#include "neuron.h"

#include <cmath>
#include <iostream>

Neuron::Neuron(): 
    in(Point{0.0, 0.0}),
    out(Point{0.0, 0.0}),
    amplification(0.0),
    sensitivity(1.0),
    bias(0.0)
{}

Neuron::Neuron(Point in, Point out, double amplification, double sensitivity, double bias):
    in(in),
    out(out),
    amplification(amplification),
    sensitivity(sensitivity),
    bias(bias)
{}

double Neuron::activationFunction(double x) const {
    x = sensitivity * (x - bias);
    double absA = std::abs(amplification);
    if (x > absA) 
        { return absA; }
    else if (x < -absA) 
        { return -absA; }
    else 
        { return x; }; 
}

ActivationPoint Neuron::operator()(const ActivationMap & activationMap) const {
    return ActivationPoint {
        out,
        activationFunction(activationMap.getActivation(in))
    };
}

