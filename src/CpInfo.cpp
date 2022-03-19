#include "../headers/CpInfo.h"

#include <stdlib.h>

CpInfo::CpInfo(u1 tag) {
  this->tag = tag;
}

CONSTANT_Utf8_info::CONSTANT_Utf8_info(FILE* fp): CpInfo(CONSTANT_Utf8) {
  this->length = u4READ(fp);
  this->bytes = (u1*) malloc(this->length * sizeof(u1));
    for (auto x = 0; x < this->length; x++)
      this->bytes[x] = u1READ(fp);
}
CONSTANT_Utf8_info::~CONSTANT_Utf8_info() {
  free(this->bytes);
}

CONSTANT_Integer_info::CONSTANT_Integer_info(FILE* fp): CpInfo(CONSTANT_Integer) {
  this->bytes = u4READ(fp);
}
CONSTANT_Integer_info::~CONSTANT_Integer_info() {}

CONSTANT_Float_info::CONSTANT_Float_info(FILE* fp): CpInfo(CONSTANT_Float) {
  this->bytes = u4READ(fp);
}
CONSTANT_Float_info::~CONSTANT_Float_info() {}

CONSTANT_Long_info::CONSTANT_Long_info(FILE* fp): CpInfo(CONSTANT_Long) {
  this->high_bytes = u4READ(fp);
  this->low_bytes = u4READ(fp);
}
CONSTANT_Long_info::~CONSTANT_Long_info() {}

CONSTANT_Double_info::CONSTANT_Double_info(FILE* fp): CpInfo(CONSTANT_Double) {
  this->high_bytes = u4READ(fp);
  this->low_bytes = u4READ(fp);
}
CONSTANT_Double_info::~CONSTANT_Double_info() {}

CONSTANT_Class_info::CONSTANT_Class_info(FILE* fp): CpInfo(CONSTANT_Class) {
  this->name_index = u2READ(fp);
}
CONSTANT_Class_info::~CONSTANT_Class_info() {}

CONSTANT_String_info::CONSTANT_String_info(FILE* fp): CpInfo(CONSTANT_String) {
  this->string_index = u2READ(fp);
}
CONSTANT_String_info::~CONSTANT_String_info() {}

CONSTANT_Fieldref_info::CONSTANT_Fieldref_info(FILE* fp): CpInfo(CONSTANT_Fieldref) {
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_Fieldref_info::~CONSTANT_Fieldref_info() {}

CONSTANT_Methodref_info::CONSTANT_Methodref_info(FILE* fp): CpInfo(CONSTANT_Methodref) {
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_Methodref_info::~CONSTANT_Methodref_info() {}

CONSTANT_InterfaceMethodref_info::CONSTANT_InterfaceMethodref_info(FILE* fp): CpInfo(CONSTANT_InterfaceMethodref) {
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_InterfaceMethodref_info::~CONSTANT_InterfaceMethodref_info() {}

CONSTANT_NameAndType_info::CONSTANT_NameAndType_info(FILE* fp): CpInfo(CONSTANT_NameAndType) {
  this->name_index = u4READ(fp);
  this->descriptor_index = u4READ(fp);
}
CONSTANT_NameAndType_info::~CONSTANT_NameAndType_info() {}

CONSTANT_MethodHandle_info::CONSTANT_MethodHandle_info(FILE* fp): CpInfo(CONSTANT_MethodHandle) {
  this->reference_kind = u1READ(fp);
  this->reference_index = u2READ(fp);
}
CONSTANT_MethodHandle_info::~CONSTANT_MethodHandle_info() {}

CONSTANT_MethodType_info::CONSTANT_MethodType_info(FILE* fp): CpInfo(CONSTANT_MethodType) {
  this->descriptor_index = u2READ(fp);
}
CONSTANT_MethodType_info::~CONSTANT_MethodType_info() {}

CONSTANT_InvokeDynamic_info::CONSTANT_InvokeDynamic_info(FILE* fp): CpInfo(CONSTANT_InvokeDynamic) {
  this->bootstrap_method_attr_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_InvokeDynamic_info::~CONSTANT_InvokeDynamic_info() {}
