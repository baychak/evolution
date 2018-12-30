#include "activation_map.h"

#include <cmath>
#include <iostream>

ActivationMap::ActivationMap() {}

ActivationMap::ActivationMap(const std::vector<ActivationPoint> & map)
    : mMap(map) {}

ActivationMap &ActivationMap::operator=(const ActivationMap &map) {
  if (this == &map) return *this;
  mMap = map.mMap;
  return *this;
}

void ActivationMap::setActivationMap(const std::vector<ActivationPoint> map) {
  mMap = map;
}

void ActivationMap::addActivationPoint(const ActivationPoint &point) {
  mMap.emplace_back(point);
}

std::vector<ActivationPoint> ActivationMap::getActivationMap() const {
  return mMap;
}

double ActivationMap::getActivation(Point point) const {
  double summa = 0.0;

  for (ActivationPoint apoint : mMap) {
    summa += std::exp(-std::pow(apoint.point.x - point.x, 2.0) -
                      std::pow(apoint.point.y - point.y, 2.0)) *
             apoint.activation;
  }

  return summa;
}

void ActivationMap::printActivationMap() const {
  std::cout << "Begin " ;
  for (ActivationPoint point : mMap) {
    std::cout << "[(" << point.point.x << "," << point.point.y
              << ")," << point.activation << "]  ";
  }
  std::cout << "End" << std::endl;
}
