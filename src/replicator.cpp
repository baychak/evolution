#include "replicator.h"

Replicator::Replicator(const LowScript &replicatorCode)
    : mNeuronMap(replicatorCode),
      mActivationMap(),
      mNN(mNeuronMap, mActivationMap) {}

HighScript Replicator::operator()(const HighScript &code) {
  mActivationMap.printActivationMap();
  
  mNN.addRandomActivation({0.0, -4.0});

  HighScript script;

  for (const HighNeuronParameters highParameters : code) {
    mNN.addActivationPoints(highParameters);
    mActivationMap.printActivationMap();
    mNN.doOneIteration();
    mActivationMap.printActivationMap();

    script.emplace_back(mNN.getHighNeuronParameters());
  }
  
  return script;
}
