#include <iostream>

#include "../headers/Methods.h"
#include "../headers/definitions.h"

using namespace std;

// constructor
Methods::Methods(FILE *fp, ConstantPool& cp) {
  // if there are no methods, stop
  this->methods_count = u2READ(fp);
  if (this->methods_count < 1) return;

  this->ReadMethodsFromFile(fp, cp);
}
// destructor
Methods::~Methods() {
  // delete all methods from vector
  for (const auto method : this->methods)
    delete method;

  this->methods.clear();
}

void Methods::ReadMethodsFromFile(FILE *fp, ConstantPool& cp) {
  for (int i = 0; i < this->methods_count; i++) {
    this->AddMethod(new Method(fp, cp));
  }
}

void Methods::AddMethod(Method* method) {
  this->methods.push_back(method);
}
