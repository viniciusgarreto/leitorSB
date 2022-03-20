#include <iostream>

#include "../headers/Fields.h"
#include "../headers/definitions.h"

using namespace std;

// constructor
Fields::Fields(FILE *fp) {
  // if there are no fields, stop
  this->fields_count = u2READ(fp);
  if (this->fields_count < 1) return;

  this->ReadFieldsFromFile(fp);
}
// destructor
Fields::~Fields() {
  // delete all fields from vector
  for (const auto field : this->fields)
    delete field;

  this->fields.clear();
}

void Fields::ReadFieldsFromFile(FILE *fp) {
  for (int i = 0; i < this->fields_count; i++) {
    this->AddField(new Field(fp));
  }
}

void Fields::AddField(Field* field) {
  this->fields.push_back(field);
}
