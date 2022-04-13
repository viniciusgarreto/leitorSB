#ifndef field_h
#define field_h

class Field;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Attribute.h"

class Field {
  public:
    Field(FILE* fp, ConstantPool& cp);
    ~Field();

    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    std::vector<Attribute*> attributes;
    void ReadAttributesFromFile(FILE* fp, ConstantPool& cp);
    void AddAttribute(Attribute* attb);

    friend ostream &operator<<(std::ostream &, const Field &);

    u2 access_flags;
    u2 name;
    u2 descriptor;
    u2 attributes_count;
};

#endif
