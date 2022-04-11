#include "../headers/JVM.h"
#include <string>

JVM* JVM::instance = nullptr;

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
  this->objects.clear();

  delete this->exception_name;
}

JVM& JVM::getInstance() {
  if (JVM::instance == nullptr) {
    // cout << "instantiating new JVM instance";
    JVM::instance = new JVM();
  }

  return *JVM::instance;
}
void JVM::removeInstance() {
  delete JVM::instance;
}

void JVM::ReadClassFile(string classfile_name) {
  this->classes.push_back(ClassFile::lerArquivo(classfile_name));
}

ClassFile& JVM::getClassFileByName(string classfile_name) {
  for (auto classFile : this->classes)
  if (classfile_name.compare(classFile->getName()) == 0)
    return *classFile;

  cout << "ERROR: tried to search for class \"" << classfile_name << "\" but couldn't find a match";
  exit(1);
}


void JVM::execute() {
  cout << "TODO: implement JVM::execute" << endl;
}
