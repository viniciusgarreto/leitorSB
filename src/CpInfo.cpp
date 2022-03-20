#include "../headers/CpInfo.h"
#include <stdlib.h>

CpInfo::CpInfo(u1 tag) {
  this->tag = tag;
}

CONSTANT_Utf8_info::CONSTANT_Utf8_info(FILE *fp) : CpInfo(CONSTANT_Utf8) {
  this->length = u2READ(fp);
  this->bytes = (u1 *)malloc(this->length * sizeof(u1));
  for (auto x = 0; x < this->length; x++)
    this->bytes[x] = u1READ(fp);
}
CONSTANT_Utf8_info::~CONSTANT_Utf8_info() {
  free(this->bytes);
}

ostream &operator<<(ostream &os, CONSTANT_Utf8_info const &m) {
  os << "CONSTANT_Utf8_info: " << endl;
  os << "length: " << (unsigned)m.length << endl;
  os << "bytes: ";
  for (int i = 0; i < m.length; i++)
    os << m.bytes[i];
  os << endl;

  return os;
};

CONSTANT_Integer_info::CONSTANT_Integer_info(FILE *fp) : CpInfo(CONSTANT_Integer) {
  this->bytes = u4READ(fp);
}
CONSTANT_Integer_info::~CONSTANT_Integer_info() {}

ostream &operator<<(ostream &os, CONSTANT_Integer_info const &m) {
  os << "CONSTANT_Integer_info: " << endl;
  os << "bytes: " << (unsigned)m.bytes << endl;
  return os;
};

CONSTANT_Float_info::CONSTANT_Float_info(FILE *fp) : CpInfo(CONSTANT_Float) {
  this->bytes = u4READ(fp);
}
CONSTANT_Float_info::~CONSTANT_Float_info() {}

ostream &operator<<(ostream &os, CONSTANT_Float_info const &m) {
  os << "CONSTANT_Float_info: " << endl;
  os << "bytes: " << (unsigned)m.bytes << endl;
  return os;
};

CONSTANT_Long_info::CONSTANT_Long_info(FILE *fp) : CpInfo(CONSTANT_Long) {
  this->high_bytes = u4READ(fp);
  this->low_bytes = u4READ(fp);
}
CONSTANT_Long_info::~CONSTANT_Long_info() {}

ostream &operator<<(ostream &os, CONSTANT_Long_info const &m) {
  os << "CONSTANT_Long_info: " << endl;
  os << "high_bytes: " << (unsigned)m.high_bytes << endl;
  os << "low_bytes: " << (unsigned)m.low_bytes << endl;
  return os;
};

CONSTANT_Double_info::CONSTANT_Double_info(FILE *fp) : CpInfo(CONSTANT_Double) {
  this->high_bytes = u4READ(fp);
  this->low_bytes = u4READ(fp);
}
CONSTANT_Double_info::~CONSTANT_Double_info() {}

ostream &operator<<(ostream &os, CONSTANT_Double_info const &m) {
  os << "CONSTANT_Double_info: " << endl;
  os << "high_bytes: " << (unsigned)m.high_bytes << endl;
  os << "low_bytes: " << (unsigned)m.low_bytes << endl;
  return os;
};

CONSTANT_Class_info::CONSTANT_Class_info(FILE *fp) : CpInfo(CONSTANT_Class) {
  this->name_index = u2READ(fp);
}
CONSTANT_Class_info::~CONSTANT_Class_info() {}

ostream &operator<<(ostream &os, CONSTANT_Class_info const &m) {
  os << "CONSTANT_Class_info: " << endl;
  os << "name_index: " << m.name_index << endl;
  return os;
};

CONSTANT_String_info::CONSTANT_String_info(FILE *fp) : CpInfo(CONSTANT_String) {
  this->string_index = u2READ(fp);
}
CONSTANT_String_info::~CONSTANT_String_info() {}

ostream &operator<<(ostream &os, CONSTANT_String_info const &m) {
  os << "CONSTANT_String_info: " << endl;
  os << "string_index: " << (unsigned)m.string_index << endl;
  return os;
};

CONSTANT_Fieldref_info::CONSTANT_Fieldref_info(FILE *fp) : CpInfo(CONSTANT_Fieldref) {
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_Fieldref_info::~CONSTANT_Fieldref_info() {}

ostream &operator<<(ostream &os, CONSTANT_Fieldref_info const &m) {
  os << "CONSTANT_Fieldref_info: " << endl;
  os << "class_index: " << (unsigned)m.class_index << endl;
  os << "name_and_type_index: " << (unsigned)m.name_and_type_index << endl;
  return os;
};

CONSTANT_Methodref_info::CONSTANT_Methodref_info(FILE *fp) : CpInfo(CONSTANT_Methodref) {
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_Methodref_info::~CONSTANT_Methodref_info() {}

ostream &operator<<(ostream &os, CONSTANT_Methodref_info const &m) {
  os << "CONSTANT_Methodref_info: " << endl;
  os << "class_index: " << (unsigned)m.class_index << endl;
  os << "name_and_type_index: " << (unsigned)m.name_and_type_index << endl;
  return os;
};

CONSTANT_InterfaceMethodref_info::CONSTANT_InterfaceMethodref_info(FILE *fp) : CpInfo(CONSTANT_InterfaceMethodref) {
  this->class_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_InterfaceMethodref_info::~CONSTANT_InterfaceMethodref_info() {}

ostream &operator<<(ostream &os, CONSTANT_InterfaceMethodref_info const &m) {
  os << "CONSTANT_InterfaceMethodref_info: " << endl;
  os << "class_index: " << (unsigned)m.class_index << endl;
  os << "name_and_type_index: " << (unsigned)m.name_and_type_index << endl;
  return os;
};

CONSTANT_NameAndType_info::CONSTANT_NameAndType_info(FILE *fp) : CpInfo(CONSTANT_NameAndType) {
  this->name_index = u2READ(fp);
  this->descriptor_index = u2READ(fp);
}
CONSTANT_NameAndType_info::~CONSTANT_NameAndType_info() {}

ostream &operator<<(ostream &os, CONSTANT_NameAndType_info const &m) {
  os << "CONSTANT_NameAndType_info: " << endl;
  os << "name_index: " << m.name_index << endl;
  os << "descriptor_index: " << (unsigned)m.descriptor_index << endl;
  return os;
};

CONSTANT_MethodHandle_info::CONSTANT_MethodHandle_info(FILE *fp) : CpInfo(CONSTANT_MethodHandle) {
  this->reference_kind = u1READ(fp);
  this->reference_index = u2READ(fp);
}
CONSTANT_MethodHandle_info::~CONSTANT_MethodHandle_info() {}

ostream &operator<<(ostream &os, CONSTANT_MethodHandle_info const &m) {
  os << "CONSTANT_MethodHandle_info: " << endl;
  os << "reference_kind: " << (unsigned)m.reference_kind << endl;
  os << "reference_index: " << (unsigned)m.reference_index << endl;
  return os;
};

CONSTANT_MethodType_info::CONSTANT_MethodType_info(FILE *fp) : CpInfo(CONSTANT_MethodType) {
  this->descriptor_index = u2READ(fp);
}
CONSTANT_MethodType_info::~CONSTANT_MethodType_info() {}

ostream &operator<<(ostream &os, CONSTANT_MethodType_info const &m) {
  os << "CONSTANT_MethodType_info: " << endl;
  os << "descriptor_index: " << (unsigned)m.descriptor_index << endl;
  return os;
};

CONSTANT_InvokeDynamic_info::CONSTANT_InvokeDynamic_info(FILE *fp) : CpInfo(CONSTANT_InvokeDynamic) {
  this->bootstrap_method_attr_index = u2READ(fp);
  this->name_and_type_index = u2READ(fp);
}
CONSTANT_InvokeDynamic_info::~CONSTANT_InvokeDynamic_info() {}

ostream &operator<<(ostream &os, CONSTANT_InvokeDynamic_info const &m) {
  os << "CONSTANT_InvokeDynamic_info: " << endl;
  os << "bootstrap_method_attr_index: " << (unsigned)m.bootstrap_method_attr_index << endl;
  os << "name_and_type_index: " << (unsigned)m.name_and_type_index << endl;
  return os;
};
