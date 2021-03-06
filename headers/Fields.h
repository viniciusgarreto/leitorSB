#ifndef fields_h
#define fields_h

class Fields;

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Field.h"

class Fields {
  public:
    Fields(FILE* fp, ConstantPool& cp);
    ~Fields();
    
    // print methods
    ostream& print(ConstantPool& cp, ostream& output = cout) const;

  private:
    std::vector<Field*> fields;
    void ReadFieldsFromFile(FILE* fp, ConstantPool& cp);
    void AddField(Field* field);

    u2 fields_count;
};

#endif
