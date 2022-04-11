#include "../headers/Frame.h"
#include "../headers/JVM.h"

Frame::Frame(string currentClass, u2 max_locals):
  constant_pool(JVM::getInstance().getClassFileByName(currentClass).getConstantPool()) {
  auto jvm = JVM::getInstance();
  this->end_retorno = jvm.pc;
  this->vetor_length = max_locals;
  this->classeCorrente = currentClass;
}
Frame::~Frame() {}
