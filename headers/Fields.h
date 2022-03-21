#ifndef fields_h
#define fields_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Field.h"

class Fields {
  public:
    Fields(FILE* fp, ConstantPool& cp);
    ~Fields();
    void printFields(ConstantPool& cp);
  private:
    std::vector<Field*> fields;
    void ReadFieldsFromFile(FILE* fp, ConstantPool& cp);
    void AddField(Field* field);

    u2 fields_count;
};

#endif
