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

void Fields::printFields(ConstantPool& cp){
  cout << "FIELDS COUNT: " << (unsigned) this->fields_count << endl;
  cout << endl;
  for(const auto field : this->fields){
    cout<< "FIELD INFO: " << endl;
    field->printField(cp);
    cout << endl;
  }
}
// ostream& operator<<(std::ostream & os, const Fields &field) {
//   os << "Fields: ";
//   for (size_t i = 0; i < field.fields_count; i++)
//   {
//     os << field.fields->name;
//   }
//   return os;
  
// }
