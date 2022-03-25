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
  
  // cout << "[FIELD] creating field with" << endl
  //   << "[FIELD]\tthis->access_flags: " << (unsigned) this->access_flags << endl
  //   << "[FIELD]\tthis->name: " << (unsigned) this->name << endl
  //   << "[FIELD]\tthis->descriptor: " << (unsigned) this->descriptor << endl
  //   << "[FIELD]\tthis->attributes_count: " << (unsigned) this->attributes_count << endl
  // << endl;

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
  // os << "Field info: " << endl;
  // os << "access_flags: " << (unsigned) field.access_flags << endl;
  // os << "name: " <<  (unsigned) field.name << endl;
  // os << "descriptor: " <<  (unsigned) field.descriptor << endl;
  // os << "attributes_count: " <<  (unsigned) field.attributes_count << endl;

  return os;
};

ostream& Field::print(ConstantPool& cp, ostream& output) const {
  cout << "access_flag: "<< (unsigned) this->access_flags << endl;
  cout << "name: "<< (unsigned)  this->name << endl;
  cout << "descriptor: "<< (unsigned)  this->descriptor << endl;
  cout << "attributes_count: "<< (unsigned)  this->attributes_count << endl;
  cout << "attributes: " << endl;

  for(const auto atb : this->attributes){
    cout<< "FIELD INFO: " << endl;
    atb->print(cp, 1, output);
    cout << endl;
  }

  return output;
}

/*
    u2 access_flags;
    u2 name;
    u2 descriptor;
    u2 attributes_count;*/
