#ifndef classes_h
#define classes_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

class Classes {
  public:
    Classes(FILE* fp);
    u2 inner_name;
    u2 inner_class_info;
    u2 inner_class_access_flags;
    u2 outer_class_info;
    void print(ConstantPool& cp, unsigned int indent = 0);
    // void print(ConstantPool& cp, unsigned int indent);
};

#endif
