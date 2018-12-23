#include "neuron_map.h"

NeuronMap::NeuronMap() : 
    mNeuronMap{
        Neuron{
            Point{1.0, 2.0},
            Point{2.0, 2.0},
            1.5,
            0.5,
            1.0
        },
        Neuron{
            Point{2.0, 2.0},
            Point{1.0, 2.0},
            -1.5,
            -1.0,
            2.0
        }
    }
{}

const std::vector<Neuron> & NeuronMap::getNeuronMap() const {
    return mNeuronMap;
}


