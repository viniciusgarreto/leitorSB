#include "../headers/definitions.h"
#include "../headers/Interfaces.h"

using namespace std;

Interfaces::Interfaces(FILE *fp) {
  this->count = u2READ(fp);
  if (this->count < 1) return;

  for (int i = 1; i < this->count; i++) {
    this->AddInterface(u2READ(fp));
  }
}
// destructor
Interfaces::~Interfaces() {
  // // delete all items from vector
  // for (const auto interface : this->interfaces)
  //   delete interface;
  this->interfaces.clear();
}

void Interfaces::AddInterface(u2 interface) {
  this->interfaces.push_back(interface);
}
