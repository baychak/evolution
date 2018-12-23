#include <iostream>

#include "neural_network.h"

int main() {
	std::cout << "Start" << std::endl;

	
	NeuronMap neuronMap;
	ActivationMap activationMap;
	NeuralNetwork NN(neuronMap, activationMap);

	activationMap.printActivationMap();

	for (size_t i = 0; i < 30; i++)
	{
		NN.doOneIteration();
		activationMap.printActivationMap();
	}

	

	// std::cout << res << std::endl;
}