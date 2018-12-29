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
    ActivationMap(const std::vector<ActivationPoint> map);

    ActivationMap& operator=(ActivationMap & map);
    void addActivationPoint(const ActivationPoint & point);
    std::vector<ActivationPoint> getActivationMap() const;
    void setActivationMap(const std::vector<ActivationPoint> map);
    double getActivation(Point point) const;
    void printActivationMap() const;

private:
    std::vector<ActivationPoint> mMap;
};

