/*
Universidade de Brasília - 2021/2
Software Básico - Turma A
Trabalho: JVM
Alunos:
            Caio Bernardon N. K. Massucato – 16/0115001
            Rafael Gonçalves de Paulo - 17/0043959
            José Vinícius Garreto Costa – 18/0123734
            Alice da Costa Borges  - 18/0011855
            Lucas Vinicius Magalhães Pinheiro - 17/0061001
*/

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

ostream& Field::print(ConstantPool& cp, ostream& output) const {
  output << "access_flag: "<< (unsigned) this->access_flags << endl;
  output << "name: (" << name << ") " << cp.getValueUTF8String(name) << endl;
  output << "descriptor: (" << (unsigned) this->descriptor << ") " << cp.getValueUTF8String(this->descriptor) << endl;
  output << "attributes_count: "<< (unsigned) this->attributes_count << endl;
  output << "attributes: " << endl;

  for(const auto atb : this->attributes){
    output << "FIELD INFO: " << endl;
    atb->print(cp, 1, output);
    output << endl;
  }

  return output;
}
