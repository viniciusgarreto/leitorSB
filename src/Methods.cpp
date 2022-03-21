#include <iostream>

#include "../headers/Methods.h"
#include "../headers/definitions.h"

using namespace std;

// constructor
Methods::Methods(FILE *fp, ConstantPool& cp) {
  // if there are no methods, stop
  this->methods_count = u2READ(fp);
  // cout << "methods count " << this->methods_count << " " << (unsigned) this->methods_count<< endl;
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
  for (size_t i = 0; i < (size_t) this->methods_count; i++) {
    // cout << "[METHODS] reading method " << i+1 << " of " << (size_t) this->methods_count << endl;
    this->AddMethod(new Method(fp, cp));
  }
}

void Methods::AddMethod(Method* method) {
  this->methods.push_back(method);
}

void Methods::printMethods(ConstantPool& cp){
  cout << "METHODS COUNT: " << (unsigned) this->methods_count << endl;
  cout << endl;
  for(const auto method : this->methods){
    cout<< "METHOD INFO: " << endl;
    method->printMethod(cp);
    cout << endl;
  }
}