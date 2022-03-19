#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"

using namespace std;

class Interfaces {
  public:
    Interfaces(FILE *fp, u2 interfaces_count);
    ~Interfaces();
  
  private:
    void AddInterfaces(u2* interface);
    std::vector<u2*> interfaces;
};


#endif
