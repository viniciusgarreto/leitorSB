#include <iostream>

#include "../headers/ConstantPool.h"
#include "../headers/definitions.h"
#include "../headers/CpInfo.h"

using namespace std;

// constructor
ConstantPool::ConstantPool(FILE *fp)
{
  this->count = u2READ(fp);
  this->ReadConstantPoolFromFile(fp);
}

// func que imprime cp_info
// define como representa cp_info como string, e pode usar isso diretamente no cout

void ConstantPool::cp_info_to_ostream(CpInfo *const(c)) {
  u1 tag = c->tag;
  switch (tag) {
  case CONSTANT_Utf8:
    cout << *((CONSTANT_Utf8_info *)c) << endl;
    break;

  case CONSTANT_Integer:
    cout << *((CONSTANT_Integer_info *)c) << endl;
    break;

  case CONSTANT_Float:
    cout << *((CONSTANT_Float_info *)c) << endl;
    break;

  case CONSTANT_Long:
    cout << *((CONSTANT_Long_info *)c) << endl;
    break;

  case CONSTANT_Double:
    cout << *((CONSTANT_Double_info *)c) << endl;
    break;

  case CONSTANT_Class:
    cout << *((CONSTANT_Class_info *)c) << endl;
    break;

  case CONSTANT_String:
    cout << *((CONSTANT_String_info *)c) << endl;
    break;

  case CONSTANT_Fieldref:
    cout << *((CONSTANT_Fieldref_info *)c) << endl;
    break;

  case CONSTANT_Methodref:
    cout << *((CONSTANT_Methodref_info *)c) << endl;
    break;

  case CONSTANT_InterfaceMethodref:
    cout << *((CONSTANT_InterfaceMethodref_info *)c) << endl;
    break;

  case CONSTANT_NameAndType:
    cout << *((CONSTANT_NameAndType_info *)c) << endl;
    break;

  case CONSTANT_MethodHandle:
    cout << *((CONSTANT_MethodHandle_info *)c) << endl;
    break;

  case CONSTANT_MethodType:
    cout << *((CONSTANT_MethodType_info *)c) << endl;
    break;

  case CONSTANT_InvokeDynamic:
    cout << *((CONSTANT_InvokeDynamic_info *)c) << endl;
    break;

  default:
    cout << "[ERROR] unidentified tag value \"" << tag << "\"." << endl;
    break;
  }
}
void ConstantPool::printConstantPool() {
  // imprime cpool count
  cout << "Constant Pool Count: " << (unsigned)this->count << endl;
  // imprime coisas da constant pool
  for (const auto cp_info : this->cp_infos) {
    cp_info_to_ostream(cp_info);
  } 
}

void ConstantPool::ReadConstantPoolFromFile(FILE *fp) {
  for (int i = 1; i < this->count; i++) {
    u1 tag = u1READ(fp);
    switch (tag) {
    // tag 1, type string (2+x bytes)
    case CONSTANT_Utf8:
      this->AddCpInfo((CpInfo *)new CONSTANT_Utf8_info(fp));
      break;

    // tag 3, type integer (4 bytes)
    case CONSTANT_Integer:
      this->AddCpInfo((CpInfo *)new CONSTANT_Integer_info(fp));
      break;

    // tag 4, type float (4 bytes)
    case CONSTANT_Float:
      this->AddCpInfo((CpInfo *)new CONSTANT_Float_info(fp));
      break;

    // tag 5, type long (8 bytes)
    case CONSTANT_Long:
      this->AddCpInfo((CpInfo *)new CONSTANT_Long_info(fp));
      // i++;
      break;

    // tag 6, type double (8 bytes)
    case CONSTANT_Double:
      this->AddCpInfo((CpInfo *)new CONSTANT_Double_info(fp));
      // i++;
      break;

    // tag 7, type classRef (2 bytes)
    case CONSTANT_Class:
      this->AddCpInfo((CpInfo *)new CONSTANT_Class_info(fp));
      break;

    // tag 8, type string ref (2 bytes)
    case CONSTANT_String:
      this->AddCpInfo((CpInfo *)new CONSTANT_String_info(fp));
      break;

    // tag 9, type fieldRef (4 bytes)
    case CONSTANT_Fieldref:
      this->AddCpInfo((CpInfo *)new CONSTANT_Fieldref_info(fp));
      break;

    // tag 10, type methodRef (4 bytes)s
    case CONSTANT_Methodref:
      this->AddCpInfo((CpInfo *)new CONSTANT_Methodref_info(fp));
      break;

    // tag 11, type interfaceMethodRef (4 bytes)
    case CONSTANT_InterfaceMethodref:
      this->AddCpInfo((CpInfo *)new CONSTANT_InterfaceMethodref_info(fp));
      break;

    // tag 12, type nameAndType (4 bytes)
    case CONSTANT_NameAndType:
      this->AddCpInfo((CpInfo *)new CONSTANT_NameAndType_info(fp));
      break;

    // tag 13, type methodHandle (3 bytes)
    case CONSTANT_MethodHandle:
      this->AddCpInfo((CpInfo *)new CONSTANT_MethodHandle_info(fp));
      break;

    // tag 14, type methodType (4 bytes)
    case CONSTANT_MethodType:
      this->AddCpInfo((CpInfo *)new CONSTANT_MethodType_info(fp));
      break;

    // tag 17, type Dynamic (4 bytes)

    // tag 18, type invokeDynamic (4 bytes)
    case CONSTANT_InvokeDynamic:
      this->AddCpInfo((CpInfo *)new CONSTANT_InvokeDynamic_info(fp));
      break;

      // tag 19, type module (2 bytes)

      // tag 20, type package (2 bytes)

    default:
      cout << "[ERROR] unidentified tag value \"" << tag << "\"." << endl;
      break;
    }
  }
}

// destructor
ConstantPool::~ConstantPool() {
  // delete all items from vector
  for (const auto cp_info : this->cp_infos)
    delete cp_info;

  this->cp_infos.clear();
}

void ConstantPool::AddCpInfo(CpInfo *cp_info) {
  this->cp_infos.push_back(cp_info);
}

CpInfo* ConstantPool::getCpInfo(u2 index) {
  if (index > this->count) return NULL;
  return this->cp_infos.at((size_t) index - 1);
}

string ConstantPool::getValueUTF8String(u2 index) {
  auto cpValue = this->getCpInfo(index);
  if (!cpValue) return string("[ERROR] index out of range");

  auto utf8Entry = (CONSTANT_Utf8_info*) this->getCpInfo(index);
  auto bytes = (char*) utf8Entry->bytes;
  auto length = (size_t) utf8Entry->length;
  return string(bytes, length);
}
