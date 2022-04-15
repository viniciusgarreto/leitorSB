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

ostream& operator<<(ostream& output, const ConstantPool& cf) {
  return cf.print(output);
}
ostream& ConstantPool::print(ostream& output) const {
  // imprime cpool count
  output << endl 
    << "Constant Pool Count: " << (unsigned)this->count << endl;

  // imprime coisas da constant pool
  for (size_t i = 0; i < this->count; i++)
  if (this->cp_infos[i] != nullptr) {
    output << i << ") ";
    this->cp_infos[i]->print(output, *this);
  }

  return output;
}

void ConstantPool::ReadConstantPoolFromFile(FILE *fp) {
  // std::cout << "[INFO] [CP] Reading constant pool from file. cp_count: " << this->count << endl;
  this->cp_infos = (CpInfo**) malloc(sizeof(CpInfo*) * this->count);
  this->cp_infos[0] = nullptr;
  for (int i = 1; i < this->count; i++) {
    u1 tag = u1READ(fp);
    // std::cout << "[INFO] [CP] reading tag " << (unsigned) tag << endl;
    switch (tag) {
    // tag 1, type string (2+x bytes)
    case CONSTANT_Utf8:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Utf8_info(fp);
      break;

    // tag 3, type integer (4 bytes)
    case CONSTANT_Integer:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Integer_info(fp);
      break;

    // tag 4, type float (4 bytes)
    case CONSTANT_Float:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Float_info(fp);
      break;

    // tag 5, type long (8 bytes)
    case CONSTANT_Long:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Long_info(fp);
      i++;
      this->cp_infos[i] = nullptr;
      break;

    // tag 6, type double (8 bytes)
    case CONSTANT_Double:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Double_info(fp);
      i++;
      this->cp_infos[i] = nullptr;
      break;

    // tag 7, type classRef (2 bytes)
    case CONSTANT_Class:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Class_info(fp);
      break;

    // tag 8, type string ref (2 bytes)
    case CONSTANT_String:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_String_info(fp);
      break;

    // tag 9, type fieldRef (4 bytes)
    case CONSTANT_Fieldref:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Fieldref_info(fp);
      break;

    // tag 10, type methodRef (4 bytes)s
    case CONSTANT_Methodref:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_Methodref_info(fp);
      break;

    // tag 11, type interfaceMethodRef (4 bytes)
    case CONSTANT_InterfaceMethodref:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_InterfaceMethodref_info(fp);
      break;

    // tag 12, type nameAndType (4 bytes)
    case CONSTANT_NameAndType:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_NameAndType_info(fp);
      break;

    // tag 13, type methodHandle (3 bytes)
    case CONSTANT_MethodHandle:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_MethodHandle_info(fp);
      break;

    // tag 14, type methodType (4 bytes)
    case CONSTANT_MethodType:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_MethodType_info(fp);
      break;

    // tag 17, type Dynamic (4 bytes)

    // tag 18, type invokeDynamic (4 bytes)
    case CONSTANT_InvokeDynamic:
      this->cp_infos[i] = (CpInfo *)new CONSTANT_InvokeDynamic_info(fp);
      break;

      // tag 19, type module (2 bytes)

      // tag 20, type package (2 bytes)

    default:
      cout << "[ERROR][CP] unidentified tag value \"" << (unsigned) tag << "\"." << endl;
      break;
    }
  }
}

// destructor
ConstantPool::~ConstantPool() {
  // clear all items
  for (size_t i = 0; i < this->count; i++)
  if (this->cp_infos[i] != nullptr)
    delete this->cp_infos[i];
  
  delete this->cp_infos;
}

CpInfo* ConstantPool::getCpInfo(u2 index) const {
  if (index > this->count) return NULL;
  return this->cp_infos[(size_t) index];
}

string ConstantPool::getValueUTF8String(u2 index) const {
  auto cpValue = this->getCpInfo(index);
  if (!cpValue) return string("[ERROR] index out of range");

  auto cpInfo = (CONSTANT_Utf8_info*) this->getCpInfo(index);

  // take care of special cases
  switch (cpInfo->tag) {
    case CONSTANT_Utf8:
      return string((char*) cpInfo->bytes, (size_t) cpInfo->length);

    case CONSTANT_Integer:
      return to_string((int) ((CONSTANT_Integer_info*)cpInfo)->bytes);

    case CONSTANT_Float:
      return to_string((*((float*)(&((CONSTANT_Float_info*)cpInfo)->bytes))) );

    case CONSTANT_Long:
      {
        uint64_t result = ((uint64_t) ((CONSTANT_Double_info*)cpInfo)->high_bytes << 32) | (uint64_t) (((CONSTANT_Double_info*)cpInfo)->low_bytes);
        return to_string(result);
      }
      break;

    case CONSTANT_Double: 
      {
        uint64_t buffer = ((uint64_t) ((CONSTANT_Double_info*)cpInfo)->high_bytes << 32) | (uint64_t) (((CONSTANT_Double_info*)cpInfo)->low_bytes);
        return to_string(*((double*)(&buffer)));
      }

    case CONSTANT_Class:
      return this->getValueUTF8String(((CONSTANT_Class_info*) cpInfo)->name_index);

    case CONSTANT_String:
      return this->getValueUTF8String(((CONSTANT_String_info*)cpInfo)->string_index);

    case CONSTANT_Fieldref:
      return this->getValueUTF8String(((CONSTANT_Fieldref_info*) cpInfo)->class_index) + string(" ") + this->getValueUTF8String(((CONSTANT_Fieldref_info*) cpInfo)->name_and_type_index);

    case CONSTANT_Methodref:
      return this->getValueUTF8String(((CONSTANT_Methodref_info*) cpInfo)->class_index) + string(".") + (this->getValueUTF8String(((CONSTANT_Methodref_info*) cpInfo)->name_and_type_index));

    case CONSTANT_InterfaceMethodref:
      return this->getValueUTF8String(((CONSTANT_InterfaceMethodref_info*) cpInfo)->class_index) + string(" ") + this->getValueUTF8String(((CONSTANT_InterfaceMethodref_info*) cpInfo)->name_and_type_index);

    case CONSTANT_NameAndType:
      return this->getValueUTF8String(((CONSTANT_NameAndType_info*) cpInfo)->name_index) + string(" : ") + this->getValueUTF8String(((CONSTANT_NameAndType_info*) cpInfo)->descriptor_index);

    case CONSTANT_MethodHandle:
      return this->getValueUTF8String(((CONSTANT_MethodHandle_info*) cpInfo)->reference_index);

    case CONSTANT_MethodType:
      return this->getValueUTF8String(((CONSTANT_MethodType_info*) cpInfo)->descriptor_index);

    case CONSTANT_InvokeDynamic:
      return this->getValueUTF8String(((CONSTANT_InvokeDynamic_info*) cpInfo)->name_and_type_index) + string(" ") + this->getValueUTF8String(((CONSTANT_InvokeDynamic_info*) cpInfo)->bootstrap_method_attr_index);

    default:
      return string("");
  }
}
