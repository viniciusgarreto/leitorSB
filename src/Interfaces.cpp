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
  output << endl 
    << "Interfaces Count: " << this->count << endl;

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
