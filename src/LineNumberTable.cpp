/*
Universidade de Brasília - 2021/2
Software Básico - Turma A
Trabalho: JVM
Alunos:
            Caio Bernardon N. K. Massucato – 16/0115001
            Rafael Gonçalves de Paulo - 17/0043959
            José Vinícius Garreto Costa – 18/0123734
            Alice da Costa Borges  - 18/0011855
            Lucas Vinicius Magalhães Pinheiro - 17/0061001
*/

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
