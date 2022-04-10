#include "../headers/JVM.h"

JVM::JVM() {
  this->frame_stack = new StackFrame();

  this->pc = 0;
  this->exception = 0;
  this->exception_name = (char*) malloc(100 * sizeof(char));
}

JVM::~JVM() {
  delete this->frame_stack;
  for (auto classFile : this->classes)
    delete classFile;
  this->classes.clear();

  delete this->exception_name;
}

void JVM::ReadClassFile(string classfile_name) {
  this->classes.push_back(ClassFile::lerArquivo(classfile_name));
}

void JVM::execute() {
  cout << "TODO: implement";
}
