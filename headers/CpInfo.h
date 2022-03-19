  #ifndef classFile_h
#define classFile_h

#include "../headers/definitions.h"
#include <stdio.h>

class CpInfo {
  // Byte de tag: indica qual o tipo de entrada na CP
  public:
    CpInfo(u1 tag);
    u1 tag;
};

class CONSTANT_Utf8_info : public CpInfo {
  public:
    CONSTANT_Utf8_info(FILE* fp);
    ~CONSTANT_Utf8_info();
    u2 length;
    u1* bytes;
};

class CONSTANT_Integer_info : public CpInfo {
  public:
    CONSTANT_Integer_info(FILE* fp);
    u4 bytes;
};

class CONSTANT_Float_info : public CpInfo {
  public:
    CONSTANT_Float_info(FILE *fp);
    u4 bytes;
};

class CONSTANT_Long_info : public CpInfo{
  public:
    CONSTANT_Long_info(FILE *fp);
    u4 high_bytes;
    u4 low_bytes;
};

class CONSTANT_Double_info : public CpInfo {
  public:
    CONSTANT_Double_info(FILE *fp);
    u4 high_bytes;
    u4 low_bytes;
};

class CONSTANT_Class_info : public CpInfo {
  public:
    CONSTANT_Class_info(FILE* fp);
    u2 name_index;
};

class CONSTANT_String_info : public CpInfo{
  public:
    CONSTANT_String_info(FILE *fp);
    u2 string_index;
};

class CONSTANT_Fieldref_info : public CpInfo {
  public:
    CONSTANT_Fieldref_info(FILE* fp);
    u2 class_index;
    u2 name_and_type_index;
};

class CONSTANT_Methodref_info : public CpInfo {
  public:
    CONSTANT_Methodref_info(FILE* fp);
    u2 class_index;
    u2 name_and_type_index;
};

class CONSTANT_InterfaceMethodref_info : public CpInfo {
  public:
    CONSTANT_InterfaceMethodref_info(FILE *fp);
    u2 class_index;
    u2 name_and_type_index;
};

class CONSTANT_NameAndType_info : public CpInfo {
  public:
    CONSTANT_NameAndType_info(FILE *fp);
    u2 name_index;
    u2 descriptor_index;
};

class CONSTANT_MethodHandle_info : public CpInfo {
  public:
    CONSTANT_MethodHandle_info(FILE *fp);
    u1 reference_kind;
    u2 reference_index;
};

class CONSTANT_MethodType_info : public CpInfo {
  public:
    CONSTANT_MethodType_info(FILE *fp);
    u2 descriptor_index;
};

class CONSTANT_InvokeDynamic_info : public CpInfo {
  public:
    CONSTANT_InvokeDynamic_info(FILE *fp);
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};

#endif
