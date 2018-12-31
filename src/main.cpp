#include <iostream>

#include "translator.h"

int main() {
  std::cout << "Start" << std::endl;

  LowScript lowTranslatorCode({
    {{0.0, 0.0}, {10.0, 0.0}, 1.0, 1.0, 0.0},
    {{0.0, 2.0}, {10.0, 2.0}, 14.0, 1.0, 0.0},
    {{0.0, 4.0}, {10.0, 4.0}, 12.0, 1.0, 0.0},
    {{0.0, 6.0}, {10.0, 6.0}, 14.0, 1.0, 0.0},
    {{0.0, 8.0}, {10.0, 8.0}, 15.0, 1.0, 0.0},
    {{0.0, 10.0}, {10.0, 10.0}, 2.0, 1.0, 0.0},
    {{0.0, 12.0}, {10.0, 12.0}, 1.0, 1.0, 0.0}
  });

  HighScript highTranslatorCode({
    {{0.0, 0.0}, {10.0, 0.0}, 1.0, 1.0, 0.0},
    {{0.0, 2.0}, {10.0, 2.0}, 14.0, 1.0, 0.0},
    {{0.0, 4.0}, {10.0, 4.0}, 12.0, 1.0, 0.0},
    {{0.0, 6.0}, {10.0, 6.0}, 14.0, 1.0, 0.0},
    {{0.0, 8.0}, {10.0, 8.0}, 15.0, 1.0, 0.0},
    {{0.0, 10.0}, {10.0, 10.0}, 2.0, 1.0, 0.0},
    {{0.0, 12.0}, {10.0, 12.0}, 1.0, 1.0, 0.0}
  });

  Translator translator(lowTranslatorCode);

  LowScript lowTranslatorCode2 = translator(highTranslatorCode);

  lowScriptDiff(lowTranslatorCode2, lowTranslatorCode);

  // LowScript translatorCode({LowNeuronParameters{Point{2.0, 2.0},
  // Point{2.0, 2.0}, 2.0, -1.2, 0.5}});

  // NeuronMap translatorNeuronMap(translatorCode);

  // ActivationMap activationMap({ActivationPoint{Point{2.0, 2.0}, 1.2}});

  // NeuralNetwork translatorNN(translatorNeuronMap, activationMap);

  // activationMap.printActivationMap();

  // for (size_t i = 0; i < 4; i++) {
  //   translatorNN.doOneIteration();
  //   translatorNN.addRandomActivation({1.0, 0.0});
  //   activationMap.printActivationMap();
  // }
}