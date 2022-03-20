#ifndef field_h
#define field_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

class Field {
  public:
    Field(FILE* fp);
    ~Field();

  private:
    std::vector<Attribute*> attributes;
    void ReadAttributesFromFile(FILE* fp);
    void AddAttribute(Attribute* attb);

    u2 access_flags;
    u2 name;
    u2 descriptor;
    u2 attributes_count;
};

#endif
