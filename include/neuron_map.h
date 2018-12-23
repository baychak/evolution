#pragma once

#include <vector>

#include "neuron.h"

class NeuronMap {
public:
    NeuronMap();

    const std::vector<Neuron> & getNeuronMap() const;

private:
    std::vector<Neuron> mNeuronMap;
};
