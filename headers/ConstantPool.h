#ifndef constant_pool_h
#define constant_pool_h

#include <vector>
#include <stdio.h>
// #include <stdlib.h>

#include "../headers/definitions.h"

using namespace std;

class ConstantPool {
  public:
    ConstantPool(FILE *fp, u2 cp_count);

  private:
    // std::vector<Component*> components;
};

#endif
