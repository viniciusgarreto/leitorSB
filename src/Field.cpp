#include <iostream>

#include "../headers/definitions.h"
#include "../headers/Field.h"

using namespace std;

// constructor
Field::Field(FILE* fp, ConstantPool& cp) {
  this->access_flags = u2READ(fp);
  this->name = u2READ(fp);
  this->descriptor = u2READ(fp);

  // if there are no attributes, stop
  this->attributes_count = u2READ(fp);
  if (this->attributes_count < 1) return;
  // read attributes
  this->ReadAttributesFromFile(fp, cp);
}
// destructor
Field::~Field() {
  // delete all attributes from vector
  for (const auto attribute : this->attributes)
    delete attribute;

  this->attributes.clear();
}

void Field::ReadAttributesFromFile(FILE* fp, ConstantPool& cp) {
  for (size_t i = 1; i < (size_t) this->attributes_count; i++) {
    // cout << i << ":" << this->attributes_count << endl;
    // cout << "in field attb creation" << endl;
    this->AddAttribute(Attribute::readAttribute(fp, cp));
  }
}

void Field::AddAttribute(Attribute* attb) {
  this->attributes.push_back(attb);
}

ostream& operator<<(std::ostream & os, const Field &field) {
  os << "Field info: "<<endl;
  os << "access_flags: " << field.access_flags << endl;
  os << "name: " << field.name << endl;
  os << "descriptor: " << field.descriptor << endl;
  os << "attributes_count: " << field.attributes_count << endl;

  return os;
};
/*
    u2 access_flags;
    u2 name;
    u2 descriptor;
    u2 attributes_count;*/
