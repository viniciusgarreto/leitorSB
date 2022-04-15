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

#include "../headers/definitions.h"
#include "../headers/Interfaces.h"
#include "../headers/ConstantPool.h"

using namespace std;

Interfaces::Interfaces(FILE *fp) {
  this->count = u2READ(fp);
  if (this->count < 1) return;

  for (int i = 0; i < this->count; i++) {
    u2 a = u2READ(fp);
    this->AddInterface(a);
  }
}
// destructor
Interfaces::~Interfaces() {
  this->interfaces.clear();
}

void Interfaces::AddInterface(u2 interface) {
  this->interfaces.push_back(interface);
}

ostream& Interfaces::print(ConstantPool& cp, ostream& output) const {
  output << "Interfaces Count: " << this->count << endl;

  if (this->count > 0) {
    output << "Interfaces: " << endl;
    for (int i = 0; i < this->count; i++) {
      output << "Interface " << i << ": " << endl
        << *cp.getCpInfo(this->interfaces[i]) << endl
      ;
    }
  }
  return output;
}
