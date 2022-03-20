#ifndef fields_h
#define fields_h

#include <vector>
#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/Field.h"

class Fields {
  public:
    Fields(FILE* fp);
    ~Fields();

  private:
    std::vector<Field*> fields;
    void ReadFieldsFromFile(FILE* fp);
    void AddField(Field* field);

    u2 fields_count;
};

#endif
