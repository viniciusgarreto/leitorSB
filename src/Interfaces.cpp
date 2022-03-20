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
  // // delete all items from vector
  // for (const auto interface : this->interfaces)
  //   delete interface;
  this->interfaces.clear();
}

void Interfaces::AddInterface(u2 interface) {
  this->interfaces.push_back(interface);
}

string Interfaces::ToString(ConstantPool& cp) {
  std::ostringstream os;
  os << "Interfaces Count: " << this->count << endl;
  os << "Interfaces: " << endl;
  for (int i = 0; i < this->count; i++) {
    os << "Interface " << i << " { "  << endl;
    os << *cp.getCpInfo(this->interfaces[i]) << endl;
    os << "}" << endl;
  }
  return os.str();
}

// ostream& operator<<(std::ostream & os, const Interfaces & inter) {
//   os << "Interfaces: " << endl;
//   for (int i = 0; i < inter.count; i++) {
//     os << "Interface " << i << ": " << (unsigned) inter.interfaces[i] << endl;
//   }
//   return os;
// }
