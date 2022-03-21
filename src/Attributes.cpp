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

void Attributes::printAttributes(ConstantPool& cp){
  cout << "ATTRIBUTES COUNT: " << (unsigned) this->attributes_count << endl;
  cout << endl;
  for(const auto attribute : this->attributes){
    cout<< "ATTRIBUTE INFO: " << endl;
    attribute->printAttribute(cp);
    cout << endl;
  }
}
