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
    void addActivationPoint(const ActivationPoint & point);
    const std::vector<ActivationPoint> & getActivationMap() const;
    void setActivationMap(const std::vector<ActivationPoint> map);
    void printActivationMap() const;

private:
    std::vector<ActivationPoint> mMap;

};

