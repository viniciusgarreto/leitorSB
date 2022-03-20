#ifndef method_h
#define method_h

#include <stdio.h>
#include <vector>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

class Method {
  public:
    Method(FILE* fp, ConstantPool& cp);
    ~Method();

  private:
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attb);
    u2 access_flags;
    u2 name;
    u2 descriptor;
    u2 attributes_count;
    std::vector<Attribute*> attributes;
};

#endif
