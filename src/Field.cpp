#include <iostream>

#include "../headers/definitions.h"
#include "../headers/Field.h"

using namespace std;

// constructor
Field::Field(FILE* fp) {
  this->access_flags = u2READ(fp);
  this->name = u2READ(fp);
  this->descriptor = u2READ(fp);

  // if there are no attributes, stop
  this->attributes_count = u2READ(fp);
  if (this->attributes_count < 1) return;
  // read attributes
  this->ReadAttributesFromFile(fp);
}
// destructor
Field::~Field() {
  // delete all attributes from vector
  for (const auto attribute : this->attributes)
    delete attribute;

  this->attributes.clear();
}

void Field::ReadAttributesFromFile(FILE* fp) {
  for (int i = 1; i < this->attributes_count; i++)
    this->AddAttribute(new Attribute(fp));
}

void Field::AddAttribute(Attribute* attb) {
  this->attributes.push_back(attb);
}
