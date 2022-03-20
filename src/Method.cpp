#include <iostream>

#include "../headers/definitions.h"
#include "../headers/Method.h"

using namespace std;

// constructor
Method::Method(FILE* fp, ConstantPool& cp) {
  this->access_flags = u2READ(fp);
  this->name = u2READ(fp);
  this->descriptor = u2READ(fp);
  this->attributes_count = u2READ(fp);

  cout << "[METHOD] creating method with" << endl
    << "[METHOD]\tthis->access_flags: " << (unsigned) this->access_flags << endl
    << "[METHOD]\tthis->name: " << (unsigned) this->name << endl
    << "[METHOD]\tthis->descriptor: " << (unsigned) this->descriptor << endl
    << "[METHOD]\tthis->attributes_count: " << (unsigned) this->attributes_count << endl
    << endl;

  // if there are no attributes, stop
  if (this->attributes_count < 1) return;

  // read attributes
  this->ReadAttributesFromFile(fp, cp);
}
// destructor
Method::~Method() {
  // delete all attributes from vector
  for (const auto attribute : this->attributes)
    delete attribute;
  this->attributes.clear();
}

void Method::ReadAttributesFromFile(FILE* fp, ConstantPool& cp) {
  cout << "[METHOD] reading attributes for method. total: " <<  this->attributes_count << endl;
  for (int i = 0; i < this->attributes_count; i++) {
    cout << "[METHOD]\t atribute " << i << "." << endl;
    this->AddAttribute(Attribute::readAttribute(fp, cp));
  }
}

void Method::AddAttribute(Attribute* attb) {
  this->attributes.push_back(attb);
}
