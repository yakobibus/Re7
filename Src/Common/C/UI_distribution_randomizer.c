// UI_distribution_randomizer.c

# include <random>
# include <iostream>

# include "UI_distribution_randomizer.h"

using std::cout ;
using std::endl ;

namespace ui_dist_rand {
  UI_Distributed_Rand::UI_Distributed_Rand (int i, int j) : _lowerBound(i), _upperBound(j),  gen(rd()), dis(_lowerBound, _upperBound) {
  }
  
  UI_Distributed_Rand::UI_Distributed_Rand (const UI_Distributed_Rand& uid) {
    if (this != &uid) {
      gen = uid.gen ;
      dis = uid.dis ;
    }
  }
  
  UI_Distributed_Rand& UI_Distributed_Rand::operator = (const UI_Distributed_Rand& uid)  {
    if (this != &uid) {
      gen = uid.gen ;
      dis = uid.dis ;
    }

    return *this ;
  }
  //
  int UI_Distributed_Rand::random (void) {
    return dis(gen);
  }
}
