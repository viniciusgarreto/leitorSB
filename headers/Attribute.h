#ifndef attribute_h
#define attribute_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

class Attribute {
  public:
    Attribute(FILE* fp, ConstantPool& cp);
    ~Attribute();

  private:
    void readInfo(FILE* fp, ConstantPool& cp);

    u2 attribute_name;
    u4 attribute_length;
    void *info;
};

#endif
