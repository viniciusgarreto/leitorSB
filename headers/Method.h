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
    void printMethod(ConstantPool& cp);

  private:
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attb);
    u2 access_flags;
    u2 name_index;
    u2 descriptor_index;
    u2 attributes_count;
    std::vector<Attribute*> attributes;
};

#endif
