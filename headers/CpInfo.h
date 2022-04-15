#ifndef cpInfo_h
#define cpInfo_h

#include "../headers/definitions.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class CpInfo {
  
  public:
    /// construtor
    CpInfo(u1 tag);
    /// indica qual o tipo de entrada na CP
    u1 tag;

    friend ostream& operator<<(ostream& out, const CpInfo& cf);
};


class CONSTANT_Utf8_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Utf8_info(FILE *fp);
  ~CONSTANT_Utf8_info();
  u2 length;
  u1 *bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Utf8_info &);
};

class CONSTANT_Integer_info : public CpInfo
{
public:
  CONSTANT_Integer_info(FILE *fp);
  ~CONSTANT_Integer_info();
  u4 bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Integer_info &);
};

class CONSTANT_Float_info : public CpInfo
{
public:
  CONSTANT_Float_info(FILE *fp);
  ~CONSTANT_Float_info();
  u4 bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Float_info &);
};

class CONSTANT_Long_info : public CpInfo
{
public:
  CONSTANT_Long_info(FILE *fp);
  ~CONSTANT_Long_info();
  u4 high_bytes;
  u4 low_bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Long_info &);
};

class CONSTANT_Double_info : public CpInfo
{
public:
  CONSTANT_Double_info(FILE *fp);
  ~CONSTANT_Double_info();
  u4 high_bytes;
  u4 low_bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Double_info &);
};

class CONSTANT_Class_info : public CpInfo
{
public:
  CONSTANT_Class_info(FILE *fp);
  ~CONSTANT_Class_info();
  u2 name_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Class_info &);
};

class CONSTANT_String_info : public CpInfo
{
public:
  CONSTANT_String_info(FILE *fp);
  ~CONSTANT_String_info();
  u2 string_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_String_info &);
};
class CONSTANT_Fieldref_info : public CpInfo
{
public:
  CONSTANT_Fieldref_info(FILE *fp);
  ~CONSTANT_Fieldref_info();
  u2 class_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Fieldref_info &);
};

class CONSTANT_Methodref_info : public CpInfo
{
public:
  CONSTANT_Methodref_info(FILE *fp);
  ~CONSTANT_Methodref_info();
  u2 class_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Methodref_info &);
};

class CONSTANT_InterfaceMethodref_info : public CpInfo
{
public:
  CONSTANT_InterfaceMethodref_info(FILE *fp);
  ~CONSTANT_InterfaceMethodref_info();
  u2 class_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_InterfaceMethodref_info &);
};

class CONSTANT_NameAndType_info : public CpInfo
{
public:
  CONSTANT_NameAndType_info(FILE *fp);
  ~CONSTANT_NameAndType_info();
  u2 name_index;
  u2 descriptor_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_NameAndType_info &);
};

class CONSTANT_MethodHandle_info : public CpInfo
{
public:
  CONSTANT_MethodHandle_info(FILE *fp);
  ~CONSTANT_MethodHandle_info();
  u1 reference_kind;
  u2 reference_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_MethodHandle_info &);
};

class CONSTANT_MethodType_info : public CpInfo
{
public:
  CONSTANT_MethodType_info(FILE *fp);
  ~CONSTANT_MethodType_info();
  u2 descriptor_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_MethodType_info &);
};

class CONSTANT_InvokeDynamic_info : public CpInfo
{
public:
  CONSTANT_InvokeDynamic_info(FILE *fp);
  ~CONSTANT_InvokeDynamic_info();
  u2 bootstrap_method_attr_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_InvokeDynamic_info &);
};

#endif
