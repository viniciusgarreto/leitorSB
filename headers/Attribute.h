#ifndef attribute_h
#define attribute_h

#include <stdio.h>

#include "../headers/definitions.h"

class Attribute {
  public:
    Attribute(FILE* fp);
    ~Attribute();

  private:
    void readInfo(FILE* fp);

    u2 attribute_name;
    u4 attribute_length;
    void *info;
};

#endif
