#ifndef line_number_table_h
#define line_number_table_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"

class LineNumberTable {
  public:
    LineNumberTable(FILE* fp);
    u2 start_pc;
    u2 line_number;
    void print(ConstantPool& cp, unsigned int indent);
};

#endif
