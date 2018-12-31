#pragma once

#include <vector>

#include "point.h"

struct HighNeuronParameters {
  const Point in;
  const Point out;
  const double amplification;
  const double sensitivity;
  const double bias;
};

typedef std::vector<HighNeuronParameters> HighScript;

struct LowNeuronParameters {
  const Point in;
  const Point out;
  const double amplification;
  const double sensitivity;
  const double bias;
};

typedef std::vector<LowNeuronParameters> LowScript;

void lowScriptDiff(const LowScript & script2, const LowScript & script1);
