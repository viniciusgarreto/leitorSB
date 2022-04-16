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

#include "../headers/ExceptionTable.h"
#include "../headers/ConstantPool.h"

ExceptionTable::ExceptionTable(FILE* fp) {
	this->start_pc = u2READ(fp);
	this->end_pc = u2READ(fp);
    this->handler_pc = u2READ(fp);
    this->catch_type = u2READ(fp);
}

ostream& ExceptionTable::print(unsigned int indent, ostream& output) const {
	indentBy(indent, output) << "start_pc: "<< (unsigned) this->start_pc << endl;
	indentBy(indent, output) << "end_pc: "<< (unsigned)  this->end_pc << endl;
    indentBy(indent, output) << "handler_pc: "<< (unsigned)  this->handler_pc << endl;
    indentBy(indent, output) << "catch_type: "<< (unsigned)  this->catch_type << endl;

	return output;
}
