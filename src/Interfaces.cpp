#include "../headers/definitions.h"
#include "../headers/Interfaces.h"

using namespace std;

Interfaces::Interfaces(FILE *fp, u2 interfaces_count) {


  for (int i = 1; i <= interfaces_count+1; i++) {
    this->AddInterface((u2*) fp);
  }
}
// destructor
Interfaces::~Interfaces() {
  // delete all items from vector
  for (const auto interface : this->interfaces)
    delete interface;

  this->interfaces.clear();
}

void Interfaces::AddInterface(u2* interface) {
  this->interfaces.push_back(interface);
}
