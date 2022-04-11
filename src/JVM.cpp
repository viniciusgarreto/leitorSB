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
  if (classfile_name == classFile->getName())
    return *classFile;

  cout << "ERROR: tried to search for class \"" << classfile_name << "\" but couldn't find a match";
  exit(1);
}


void JVM::execute() {
  if (this->classes.empty()) {
    cout << "[ERROR] tried to execute jvm, but no classfiles loaded" << endl;
    exit(1);
  }

  // class being executed
  auto exec_class = this->classes.at(0);

  // execute clint and main methods, if they exist.
  auto clInit = exec_class->getCLinit();
  if (clInit) clInit->execute(*this, *exec_class, true);

  auto main = exec_class->getMain();
  if (main) main->execute(*this, *exec_class, true);

  if (!main && !clInit) {
    cout << "[ERROR] tried to execute jvm, but loaded class has no clinit or main method" << endl;
    exit(1);
  }
}

void JVM::pushFrame(ClassFile& current_class, u2 max_locals) {
  cout << "TODO: implement JVM::pushFrame" << endl;
}
