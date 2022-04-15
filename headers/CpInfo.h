#ifndef cpInfo_h
#define cpInfo_h

class CpInfo;

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class CpInfo {
  
  public:
    /// construtor
    CpInfo(u1 tag);
    /// indica qual o tipo de entrada na CP
    u1 tag;

    ostream& print(ostream& out, const ConstantPool& cp);
};

// Tipos de entrada da CP
class CONSTANT_Utf8_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Utf8_info(FILE *fp);
  ~CONSTANT_Utf8_info();
  u2 length;
  u1 *bytes;
  ostream& print(ostream& out);
};

class CONSTANT_Integer_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Integer_info(FILE *fp);
  ~CONSTANT_Integer_info();
  u4 bytes;
  ostream& print(ostream& out);
};

class CONSTANT_Float_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Float_info(FILE *fp);
  ~CONSTANT_Float_info();
  u4 bytes;
  ostream& print(ostream& out);
};

class CONSTANT_Long_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Long_info(FILE *fp);
  ~CONSTANT_Long_info();
  u4 high_bytes;
  u4 low_bytes;
  ostream& print(ostream& out);
};

class CONSTANT_Double_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Double_info(FILE *fp);
  ~CONSTANT_Double_info();
  u4 high_bytes;
  u4 low_bytes;
  ostream& print(ostream& out);
};

class CONSTANT_Class_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Class_info(FILE *fp);
  ~CONSTANT_Class_info();
  u2 name_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_String_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_String_info(FILE *fp);
  ~CONSTANT_String_info();
  u2 string_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};
class CONSTANT_Fieldref_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Fieldref_info(FILE *fp);
  ~CONSTANT_Fieldref_info();
  u2 class_index;
  u2 name_and_type_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_Methodref_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Methodref_info(FILE *fp);
  ~CONSTANT_Methodref_info();
  u2 class_index;
  u2 name_and_type_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_InterfaceMethodref_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_InterfaceMethodref_info(FILE *fp);
  ~CONSTANT_InterfaceMethodref_info();
  u2 class_index;
  u2 name_and_type_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_NameAndType_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_NameAndType_info(FILE *fp);
  ~CONSTANT_NameAndType_info();
  u2 name_index;
  u2 descriptor_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_MethodHandle_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_MethodHandle_info(FILE *fp);
  ~CONSTANT_MethodHandle_info();
  u1 reference_kind;
  u2 reference_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_MethodType_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_MethodType_info(FILE *fp);
  ~CONSTANT_MethodType_info();
  u2 descriptor_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

class CONSTANT_InvokeDynamic_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_InvokeDynamic_info(FILE *fp);
  ~CONSTANT_InvokeDynamic_info();
  u2 bootstrap_method_attr_index;
  u2 name_and_type_index;
  ostream& print(ostream& out, const ConstantPool& cp);
};

#endif
