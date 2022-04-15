#include "../headers/CpInfo.h"
#include <stdlib.h>

CpInfo::CpInfo(u1 tag)
{
  this->tag = tag;
}

CONSTANT_Utf8_info::CONSTANT_Utf8_info(FILE *fp) : CpInfo(CONSTANT_Utf8)
{
  this->length = u2READ(fp);
  this->bytes = (u1 *)malloc(this->length * sizeof(u1));
  for (auto x = 0; x < this->length; x++)
    this->bytes[x] = u1READ(fp);
}
CONSTANT_Utf8_info::~CONSTANT_Utf8_info()
{
  free(this->bytes);
}

ostream& CONSTANT_Utf8_info::print(ostream& os) {
  os << "CONSTANT_Utf8_info: " << endl;
  os << "length: " << (unsigned) this->length << endl;
  os << "bytes: ";
  for (int i = 0; i < this->length; i++)
    os << this->bytes[i];
  os << endl;

  return os;
};

CONSTANT_Integer_info::CONSTANT_Integer_info(FILE *fp) : CpInfo(CONSTANT_Integer)
{
  this->bytes = u4READ(fp);
}
CONSTANT_Integer_info::~CONSTANT_Integer_info() {}

ostream& CONSTANT_Integer_info::print(ostream& os) {
  os << "CONSTANT_Integer_info: " << endl;
  os << "bytes: 0x" << hex << (unsigned) this->bytes << dec << endl;
  return os;
};

CONSTANT_Float_info::CONSTANT_Float_info(FILE *fp) : CpInfo(CONSTANT_Float)
{
  this->bytes = u4READ(fp);
}
CONSTANT_Float_info::~CONSTANT_Float_info() {}

ostream& CONSTANT_Float_info::print(ostream& os) {
  os << "CONSTANT_Float_info: " << endl;
  os << "bytes: 0x" << hex << (unsigned) this->bytes << dec << endl;
  return os;
};

CONSTANT_Long_info::CONSTANT_Long_info(FILE *fp) : CpInfo(CONSTANT_Long)
{
  this->high_bytes = u4READ(fp);
  this->low_bytes = u4READ(fp);
}
CONSTANT_Long_info::~CONSTANT_Long_info() {}

ostream& CONSTANT_Long_info::print(ostream& os) {
  os << "CONSTANT_Long_info: " << endl;
  os << "high_bytes: 0x" << hex << this->high_bytes << dec << endl;
  os << "low_bytes: 0x" << hex << this->low_bytes << dec << endl;
  return os;
};

CONSTANT_Double_info::CONSTANT_Double_info(FILE *fp) : CpInfo(CONSTANT_Double)
{
  this->high_bytes = u4READ(fp);
  this->low_bytes = u4READ(fp);
}
CONSTANT_Double_info::~CONSTANT_Double_info() {}

ostream& CONSTANT_Double_info::print(ostream& os) {
  os << "CONSTANT_Double_info: " << endl;
  os << "high_bytes: 0x" << hex << this->high_bytes << dec << endl;
  os << "low_bytes: 0x" << hex << this->low_bytes << dec << endl;
  return os;
};

CONSTANT_Class_info::CONSTANT_Class_info(FILE *fp) : CpInfo(CONSTANT_Class)
{
  this->name_index = u2READ(fp);
}
CONSTANT_Class_info::~CONSTANT_Class_info() {}

ostream& CONSTANT_Class_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_Class_info: " << endl;
  os << "name_index: (" << (unsigned) this->name_index << ") " << cp.getValueUTF8String(this->name_index) << endl;
  return os;
};

CONSTANT_String_info::CONSTANT_String_info(FILE *fp) : CpInfo(CONSTANT_String)
{
  this->string_index = u2READ(fp);
}
CONSTANT_String_info::~CONSTANT_String_info() {}

ostream& CONSTANT_String_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_String_info: " << endl;
  os << "string_index: (" << (unsigned) this->string_index << ") " << cp.getValueUTF8String(this->string_index) << endl;
  return os;
};

CONSTANT_Fieldref_info::CONSTANT_Fieldref_info(FILE *fp) : CpInfo(CONSTANT_Fieldref)
{
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_Fieldref_info::~CONSTANT_Fieldref_info() {}

ostream& CONSTANT_Fieldref_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_Fieldref_info: " << endl;
  os << "class_index: (" << (unsigned) this->class_index << ") " << cp.getValueUTF8String(this->class_index) << endl;
  os << "name_and_type_index: (" << (unsigned) this->name_and_type_index << ") " << cp.getValueUTF8String(this->name_and_type_index) << endl;
  return os;
};

CONSTANT_Methodref_info::CONSTANT_Methodref_info(FILE *fp) : CpInfo(CONSTANT_Methodref)
{
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_Methodref_info::~CONSTANT_Methodref_info() {}

ostream& CONSTANT_Methodref_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_Methodref_info: " << endl;
  os << "class_index: (" << (unsigned) this->class_index << ") " << cp.getValueUTF8String(this->class_index) << endl;
  os << "name_and_type_index: (" << (unsigned) this->name_and_type_index << ") " << cp.getValueUTF8String(this->name_and_type_index) << endl;
  return os;
};

CONSTANT_InterfaceMethodref_info::CONSTANT_InterfaceMethodref_info(FILE *fp) : CpInfo(CONSTANT_InterfaceMethodref)
{
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_InterfaceMethodref_info::~CONSTANT_InterfaceMethodref_info() {}

ostream& CONSTANT_InterfaceMethodref_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_InterfaceMethodref_info: " << endl;
  os << "class_index: (" << (unsigned) this->class_index << ") " << cp.getValueUTF8String(this->class_index) << endl;
  os << "name_and_type_index: (" << (unsigned) this->name_and_type_index << ") " << cp.getValueUTF8String(this->name_and_type_index) << endl;
  return os;
};

CONSTANT_NameAndType_info::CONSTANT_NameAndType_info(FILE *fp) : CpInfo(CONSTANT_NameAndType)
{
  this->name_index = u2READ(fp);
  this->descriptor_index = u2READ(fp);
}
CONSTANT_NameAndType_info::~CONSTANT_NameAndType_info() {}

ostream& CONSTANT_NameAndType_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_NameAndType_info: " << endl;
  os << "name_index: (" << (unsigned) this->name_index << ") " << cp.getValueUTF8String(this->name_index) << endl;
  os << "descriptor_index: (" << (unsigned) this->descriptor_index << ") " << cp.getValueUTF8String(this->descriptor_index) << endl;
  return os;
};

CONSTANT_MethodHandle_info::CONSTANT_MethodHandle_info(FILE *fp) : CpInfo(CONSTANT_MethodHandle)
{
  this->reference_kind = u1READ(fp);
  this->reference_index = u2READ(fp);
}
CONSTANT_MethodHandle_info::~CONSTANT_MethodHandle_info() {}

ostream& CONSTANT_MethodHandle_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_MethodHandle_info: " << endl;
  os << "reference_kind: " << (unsigned) this->reference_kind << endl;
  os << "reference_index: (" << (unsigned) this->reference_index << ") " << cp.getValueUTF8String(this->reference_index) << endl;
  return os;
};

CONSTANT_MethodType_info::CONSTANT_MethodType_info(FILE *fp) : CpInfo(CONSTANT_MethodType)
{
  this->descriptor_index = u2READ(fp);
}
CONSTANT_MethodType_info::~CONSTANT_MethodType_info() {}

ostream& CONSTANT_MethodType_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_MethodType_info: " << endl;
  os << "descriptor_index: (" << (unsigned) this->descriptor_index << ") " << cp.getValueUTF8String(this->descriptor_index) << endl;
  return os;
};

CONSTANT_InvokeDynamic_info::CONSTANT_InvokeDynamic_info(FILE *fp) : CpInfo(CONSTANT_InvokeDynamic)
{
  this->bootstrap_method_attr_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_InvokeDynamic_info::~CONSTANT_InvokeDynamic_info() {}

ostream& CONSTANT_InvokeDynamic_info::print(ostream& os, const ConstantPool& cp) {
  os << "CONSTANT_InvokeDynamic_info: " << endl;
  os << "bootstrap_method_attr_index: " << (unsigned) this->bootstrap_method_attr_index << endl;
  os << "name_and_type_index: (" << (unsigned) this->name_and_type_index << ") " << cp.getValueUTF8String(this->name_and_type_index) << endl;
  return os;
};

ostream& CpInfo::print(ostream& os, const ConstantPool& cp) {
  u1 tag = this->tag;
  switch (tag) {
  case CONSTANT_Utf8:
    ((CONSTANT_Utf8_info*) this)->print(os) << endl;
    break;

  case CONSTANT_Integer:
    ((CONSTANT_Integer_info*) this)->print(os) << endl;
    break;

  case CONSTANT_Float:
    ((CONSTANT_Float_info*) this)->print(os) << endl;
    break;

  case CONSTANT_Long:
    ((CONSTANT_Long_info*) this)->print(os) << endl;
    break;

  case CONSTANT_Double:
    ((CONSTANT_Double_info*) this)->print(os) << endl;
    break;

  case CONSTANT_Class:
    ((CONSTANT_Class_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_String:
    ((CONSTANT_String_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_Fieldref:
    ((CONSTANT_Fieldref_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_Methodref:
    ((CONSTANT_Methodref_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_InterfaceMethodref:
    ((CONSTANT_InterfaceMethodref_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_NameAndType:
    ((CONSTANT_NameAndType_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_MethodHandle:
    ((CONSTANT_MethodHandle_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_MethodType:
    ((CONSTANT_MethodType_info*) this)->print(os, cp) << endl;
    break;

  case CONSTANT_InvokeDynamic:
    ((CONSTANT_InvokeDynamic_info*) this)->print(os, cp) << endl;
    break;

  default:
    os << "[ERROR][CP-INFO] unidentified tag value \"" << (unsigned) tag << "\". " << (unsigned) this->tag << endl;
    break;
  }
  return os;
};
