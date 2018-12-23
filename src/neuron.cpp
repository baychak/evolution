#include "neuron.h"

#include <cmath>
#include <iostream>

Neuron::Neuron(): 
    in(Point{0.0, 0.0}),
    out(Point{0.0, 0.0}),
    amplification(0.0),
    bias(0.0),
    sensitivity(1.0)
{}

ActivationPoint Neuron::operator()(const std::vector<ActivationPoint> & activationMap) const {
    double x = getActivation(activationMap);
    return ActivationPoint {
        out,
        x + amplification * std::tanh(sensitivity * (x - bias))
    };
}

double Neuron::getActivation(const std::vector<ActivationPoint> & activationMap) const {
    
    for(ActivationPoint point : activationMap)
    {
        std::cout << "Neuron::getActivation()" << std::endl;
    }

    return 1.0;
    
}
