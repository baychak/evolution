#include "activation_map.h"

#include <iostream>

ActivationMap::ActivationMap() :
    mMap{ActivationPoint{Point{2.0, 2.0}, -1.0}, ActivationPoint{Point{2.0, 2.0}, -1.0}}  
{}


void ActivationMap::addActivationPoint(const ActivationPoint & point) {
    
}

const std::vector<ActivationPoint> & ActivationMap::getActivationMap() const {
    return mMap;
}

void ActivationMap::setActivationMap(const std::vector<ActivationPoint> map) {
    mMap = map;
}

void ActivationMap::printActivationMap() const {
    for (ActivationPoint point : mMap) {
        std::cout << "x: " << point.point.x << " y: " << point.point.y << " act: " << point.activation << std::endl;
    }
}


