#ifndef attributes_h
#define attributes_h

class Attributes;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

class Attributes {
  public:
    Attributes(FILE* fp, ConstantPool& cp);
    ~Attributes();
    
    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attributes);
    std::vector<Attribute*> attributes;
    u2 attributes_count;
};

#endif
