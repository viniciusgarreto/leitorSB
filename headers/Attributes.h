#ifndef attributes_h
#define attributes_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

class Attributes {
  public:
    Attributes(FILE* fp, ConstantPool& cp);
    ~Attributes();
    // void printAttributes();

  private:
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attributes);
    std::vector<Attribute*> attributes;
    u2 attributes_count;
};

#endif
