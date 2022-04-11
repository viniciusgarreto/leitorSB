#include "../headers/Frame.h"
#include "../headers/JVM.h"

Frame::Frame(string currentClass, u2 max_locals) {
  this->end_retorno = JVM::getInstance().pc;
  this->vetor_length = max_locals;
  this->classeCorrente = currentClass;
  // TODO: this->cp
}
Frame::~Frame() {}
