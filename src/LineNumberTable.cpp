#include "../headers/LineNumberTable.h"
#include "../headers/ConstantPool.h"

LineNumberTable::LineNumberTable(FILE* fp) {
	this->start_pc = u2READ(fp);
	this->line_number = u2READ(fp);
}

void LineNumberTable::print(ConstantPool& cp, unsigned int indent) {
	indentBy(indent);
  cout << "start_pc: "<< (unsigned) this->start_pc << endl;
	indentBy(indent);
  cout << "line_number: "<< (unsigned)  this->line_number << endl;
}
