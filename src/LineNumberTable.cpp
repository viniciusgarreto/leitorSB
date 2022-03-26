#include "../headers/LineNumberTable.h"
#include "../headers/ConstantPool.h"

LineNumberTable::LineNumberTable(FILE* fp) {
	this->start_pc = u2READ(fp);
	this->line_number = u2READ(fp);
}

ostream& LineNumberTable::print(unsigned int indent, ostream& output) const {
	indentBy(indent, output) << "start_pc: "<< (unsigned) this->start_pc << endl;
	indentBy(indent, output) << "line_number: "<< (unsigned)  this->line_number << endl;

	return output;
}
