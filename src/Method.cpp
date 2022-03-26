#include <iostream>

#include "../headers/definitions.h"
#include "../headers/Method.h"

using namespace std;

// constructor
Method::Method(FILE* fp, ConstantPool& cp) {
  this->access_flags = u2READ(fp);
  this->name_index = u2READ(fp);
  this->descriptor_index = u2READ(fp);
  this->attributes_count = u2READ(fp);


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
  // cout << "[METHOD] reading attributes for method. total: " <<  this->attributes_count << endl;
  for (int i = 0; i < this->attributes_count; i++) {
    // cout << "[METHOD]\t atribute " << i << "." << endl;
    this->AddAttribute(Attribute::readAttribute(fp, cp));
  }
}

void Method::AddAttribute(Attribute* attb) {
  this->attributes.push_back(attb);
}

ostream& Method::print(ConstantPool& cp, ostream& output) const {
  output << "access_flag: "<< (unsigned) this->access_flags << endl;
  output << "name: "<< (unsigned)  this->name_index << endl;
  output << "descriptor: "<< (unsigned)  this->descriptor_index << endl;
  output << "attributes_count: "<< (unsigned)  this->attributes_count << endl;
  
	for (auto atb : this->attributes)
		atb->print(cp, 1, output);

  return output;
}
