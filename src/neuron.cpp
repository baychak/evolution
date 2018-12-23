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

Neuron::Neuron(Point in, Point out, double amplification, double bias, double sensitivity):
    in(in),
    out(out),
    amplification(amplification),
    bias(bias),
    sensitivity(sensitivity)
{}

ActivationPoint Neuron::operator()(const std::vector<ActivationPoint> & activationMap) const {
    double x = getActivation(activationMap);
    return ActivationPoint {
        out,
        x + amplification * std::tanh(sensitivity * (x - bias))
    };
}

double Neuron::getActivation(const std::vector<ActivationPoint> & activationMap) const {
    
    double summa = 0.0;

    for (ActivationPoint point : activationMap) {
        summa += std::exp(-std::pow(point.point.x - in.x, 2.0) - std::pow(point.point.y - in.y, 2.0))
            * point.activation;
    }

    //std::cout << "Neuron::getActivation(): " << summa << std::endl;
    return summa;
}
