#pragma once

#include <vector>

#include "point.h"

struct NeuronParameters {
  const Point in;
  const Point out;
  const double amplification;
  const double sensitivity;
  const double bias;
};

typedef std::vector<NeuronParameters> NeuronScript;
