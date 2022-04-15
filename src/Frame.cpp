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

#include "../headers/Frame.h"
#include "../headers/JVM.h"

Frame::Frame(ClassFile& currentClass, u2 max_locals):
  constant_pool(currentClass.getConstantPool()) {
  auto jvm = JVM::getInstance();
  this->end_retorno = jvm.pc;
  this->vetor_length = max_locals;
  this->classeCorrente = currentClass.getName();
}
Frame::~Frame() {}
string Frame::getClassName() { return this->classeCorrente; }
