#include "translator.h"

Translator::Translator(const LowScript &tranlatorCode)
    : mNeuronMap(tranlatorCode),
      mActivationMap(),
      mNN(mNeuronMap, mActivationMap) {}

LowScript Translator::operator()(const HighScript &code) {
  mActivationMap.printActivationMap();

  LowScript script;

  for (const HighNeuronParameters highParameters : code) {
    mNN.addActivationPoints(highParameters);
    mNN.doOneIteration();
    mActivationMap.printActivationMap();

    script.emplace_back(mNN.getLowNeuronParameters());
  }
  
  return script;
}
