#include "../headers/Attributes.h"

// constructor
Attributes::Attributes(FILE *fp, ConstantPool& cp) {
  // if there are no attributes, stop
  this->attributes_count = u2READ(fp);
  // cout << "[ATTRIBUTES] Reading attributes. count: " << (unsigned) this->attributes_count << endl;
  if (this->attributes_count < 1) return;

  this->ReadAttributesFromFile(fp, cp);
}
// destructor
Attributes::~Attributes() {
  // delete all attributes from vector
  for (const auto attribute : this->attributes)
    delete attribute;

  this->attributes.clear();
}

void Attributes::ReadAttributesFromFile(FILE *fp, ConstantPool& cp) {
  for (size_t i = 0; i < (size_t) this->attributes_count; i++) {
    this->AddAttribute(Attribute::readAttribute(fp, cp));
  }
}

void Attributes::AddAttribute(Attribute* attb) {
  this->attributes.push_back(attb);
}

void AddAttribute(Attribute* attributes);

ostream& Attributes::print(ConstantPool& cp, ostream& output) const {
  output << "Attributes Count: " << (unsigned) this->attributes_count << endl;
  output << endl;
  for (const auto attribute : this->attributes) {
    output << "ATTRIBUTE INFO: " << endl;
    attribute->print(cp, 1, output);
    output << endl;
  }

  return output;
}
