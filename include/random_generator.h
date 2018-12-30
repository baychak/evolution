#pragma once

#include <random>

class RandomGenerator {
 public:
  RandomGenerator(double mean, double sigma);

  double getNormalValue();

 private:
  double mMean;
  double mSigma;
  std::mt19937 mGenerator;
  std::normal_distribution<double> mDistribution;
};
