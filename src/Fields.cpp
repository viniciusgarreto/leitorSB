#include <iostream>

#include "../headers/Fields.h"
#include "../headers/definitions.h"

using namespace std;

// constructor
Fields::Fields(FILE *fp, ConstantPool& cp) {
  // if there are no fields, stop
  this->fields_count = u2READ(fp);
  // cout << "fields count " << (unsigned) this->fields_count << endl;
  if (this->fields_count < 1) return;

  this->ReadFieldsFromFile(fp, cp);
}
// destructor
Fields::~Fields() {
  // delete all fields from vector
  for (const auto field : this->fields)
    delete field;

  this->fields.clear();
}

void Fields::ReadFieldsFromFile(FILE *fp, ConstantPool& cp) {
  for (int i = 0; i < this->fields_count; i++) {
    this->AddField(new Field(fp, cp));
  }
}

void Fields::AddField(Field* field) {
  this->fields.push_back(field);
}

// print methods
ostream& Fields::print(ConstantPool& cp, ostream& output) const {
  output << "Fields Count: " << (unsigned) this->fields_count << endl;
  output << endl;
  for(const auto field : this->fields){
    output << "Field Info: " << endl;
    field->print(cp, output);
    output << endl;
  }
}
