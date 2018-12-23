#include <iostream>

#include "neural_network.h"

int main() {
	std::cout << "Start" << std::endl;

	
	NeuronMap neuronMap;
	ActivationMap activationMap;
	NeuralNetwork NN(neuronMap, activationMap);

	activationMap.printActivationMap();

	NN.doOneIteration();
	activationMap.printActivationMap();

	

	// std::cout << res << std::endl;
}