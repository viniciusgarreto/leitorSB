#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"

using namespace std;

class Interfaces {
  public:
    Interfaces(FILE *fp);
    ~Interfaces();
  
  private:
    void AddInterface(u2 interface);
    std::vector<u2> interfaces;
    u2 count;
};


#endif
