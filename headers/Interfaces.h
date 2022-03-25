#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

using namespace std;

class Interfaces {
  public:
    Interfaces(FILE *fp);
    ~Interfaces();

    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    void AddInterface(u2 interface);
    std::vector<u2> interfaces;
    u2 count;
};


#endif
