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
