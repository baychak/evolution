#include "random_generator.h"
#include <chrono>

RandomGenerator::RandomGenerator(double mean, double sigma)
    : mMean(mean),
      mSigma(sigma),
      mGenerator(std::chrono::system_clock::now().time_since_epoch().count()),
      mDistribution(mean, sigma) {}

double RandomGenerator::getNormalValue() { return mDistribution(mGenerator); }
