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

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

#endif
