#include "neuron_script.h"

#include <iostream>

void lowScriptDiff(const LowScript & script2, const LowScript & script1) {
    
  for (size_t i = 0; i < script1.size(); i++) {
    std::cout << script2[i].in.x - script1[i].in.x << " " << script2[i].in.y - script1[i].in.y << " " 
    << script2[i].out.x - script1[i].out.x << " " << script2[i].out.y - script1[i].out.y << " " 
    << script2[i].amplification - script1[i].amplification << " " 
    << script2[i].sensitivity - script1[i].sensitivity << " " 
    << script2[i].bias - script1[i].bias << " " 
    << std::endl;
  }
}
