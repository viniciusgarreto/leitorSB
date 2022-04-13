#ifndef exception_table_h
#define exception_table_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

class ExceptionTable {
  public:
    ExceptionTable(FILE* fp);
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

#endif
