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

#include "../headers/Classes.h"
#include "../headers/ConstantPool.h"
#include "../headers/definitions.h"

#include <iostream>

using namespace std;

Classes::Classes(FILE* fp) {
	this->inner_class_info = u2READ(fp);
	this->outer_class_info = u2READ(fp);
	this->inner_name = u2READ(fp);
	this->inner_class_access_flags = u2READ(fp);

  cout << "[CLASSES] creating class with" << endl
    << "[CLASSES]\tthis->inner_class_info: " << (unsigned) this->inner_class_info << endl
    << "[CLASSES]\tthis->outer_class_info: " << (unsigned) this->outer_class_info << endl
    << "[CLASSES]\tthis->inner_name: " << (unsigned) this->inner_name << endl
    << "[CLASSES]\tthis->inner_class_access_flags: " << (unsigned) this->inner_class_access_flags << endl
	<< endl;
}

void Classes::print(unsigned int indent) {
	indentBy(indent);
  cout << "inner_class_info: "<< (unsigned) this->inner_class_info << endl;
	indentBy(indent);
  cout << "outer_class_info: "<< (unsigned)  this->outer_class_info << endl;
  indentBy(indent);
  cout << "inner_name: "<< (unsigned)  this->inner_name << endl;
  indentBy(indent);
  cout << "inner_class_access_flags: "<< (unsigned)  this->inner_class_access_flags << endl;
}
