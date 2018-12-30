#pragma once

#include <vector>

#include "point.h"

struct ActivationPoint {
  Point point;
  double activation;
};

class ActivationMap {
 public:
  ActivationMap();
  ActivationMap(const std::vector<ActivationPoint> & map);

  ActivationMap& operator=(const ActivationMap& map);

  void setActivationMap(const std::vector<ActivationPoint> map);
  void addActivationPoint(const ActivationPoint& point);
  
  std::vector<ActivationPoint> getActivationMap() const;
  double getActivation(Point point) const;

  void printActivationMap() const;

 private:
  std::vector<ActivationPoint> mMap;
};
