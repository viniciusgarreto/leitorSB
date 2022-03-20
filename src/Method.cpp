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

  // if there are no attributes, stop
  this->attributes_count = u2READ(fp);
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
  for (int i = 1; i < this->attributes_count; i++) {
    // cout << "in method attb creation" << endl;
    this->AddAttribute(Attribute::readAttribute(fp, cp));
  }
}

void Method::AddAttribute(Attribute* attb) {
  this->attributes.push_back(attb);
}
