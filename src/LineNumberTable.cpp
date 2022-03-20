#include "../headers/LineNumberTable.h"

LineNumberTable::LineNumberTable(FILE* fp) {
	this->start_pc = u2READ(fp);
	this->line_number = u2READ(fp);
}
