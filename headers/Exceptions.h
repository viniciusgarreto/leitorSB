#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

using namespace std;

class Exceptions {
  public:
    Exceptions(FILE *fp);
    ~Exceptions();
    string ToString(ConstantPool& cp);

  private:
    std::vector<u2> exceptions;
    u2 count;
};


#endif
