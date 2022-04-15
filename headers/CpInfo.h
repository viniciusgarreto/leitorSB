/*
Universidade de Brasília - 2021/2
Software Básico - Turma A
Trabalho: JVM
Alunos:
            Caio Bernardon N. K. Massucato – 16/0115001
            Rafael Gonçalves de Paulo - 17/0043959
            José Vinícius Garreto Costa – 18/0123734
            Alice da Costa Borges  - 18/0011855
            Lucas Vinicius Magalhães Pinheiro - 17/0061001
*/

#ifndef cpInfo_h
#define cpInfo_h

#include "../headers/definitions.h"
#include <stdio.h>
#include <iostream>

using namespace std;

/**
* @file CpInfo.h
* @brief Cada item na tabela constant pool deve começar com uma tag de 1 byte indicando o tipo de entrada cp info.
*/

class CpInfo {
  
  public:
    /// construtor
    CpInfo(u1 tag);
    /// indica qual o tipo de entrada na CP
    u1 tag;

    friend ostream& operator<<(ostream& out, const CpInfo& cf);
};

/// Constant pool tags - tipos de entrada da CP
  
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

/**
* As classes CONSTANT_Integer_info e CONSTANT_Float_info representam 4-byte numerico (int e float) constantes
* - tag - O atributo tag tem o valor da CONSTANT_Integer_info e CONSTANT_Float_info, respectivamente 3 e 4
* - bytes - O atributo bytes represents the value de int e float constante.
*/
class CONSTANT_Integer_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Integer_info(FILE *fp);
  ~CONSTANT_Integer_info();
  u4 bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Integer_info &);
};
/**
* As classes CONSTANT_Integer_info e CONSTANT_Float_info representam 4-byte numerico (int e float) constantes
* - tag - O atributo tag tem o valor da CONSTANT_Integer_info e CONSTANT_Float_info, respectivamente 3 e 4
* - bytes - O atributo bytes represents the value de int e float constante.
*/
class CONSTANT_Float_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Float_info(FILE *fp);
  ~CONSTANT_Float_info();
  u4 bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Float_info &);
};

/**
*  As classes CONSTANT_Long_info e CONSTANT_Double_info representam 8-byte numerico (long e double) constantes
* - tag: O atributo tag tem o valor da CONSTANT_Long_info e CONSTANT_Double_info, respectivamente 5 e 6
* - high_bytes e low_bytes: Esses atributos da CONSTANT_Long_info e CONSTANT_Double_info juntos representam o valor de long ou double constante.
*/
class CONSTANT_Long_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Long_info(FILE *fp);
  ~CONSTANT_Long_info();
  u4 high_bytes;
  u4 low_bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Long_info &);
};
/**
*  As classes CONSTANT_Long_info e CONSTANT_Double_info representam 8-byte numerico (long e double) constantes
* - tag: O atributo tag tem o valor da CONSTANT_Long_info e CONSTANT_Double_info, respectivamente 5 e 6
* - high_bytes e low_bytes: Esses atributos da CONSTANT_Long_info e CONSTANT_Double_info juntos representam o valor de long ou double constante.
*/
class CONSTANT_Double_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Double_info(FILE *fp);
  ~CONSTANT_Double_info();
  u4 high_bytes;
  u4 low_bytes;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Double_info &);
};

///Classe usada para representar uma classe ou interface
class CONSTANT_Class_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Class_info(FILE *fp);
  ~CONSTANT_Class_info();
  u2 name_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Class_info &);
};

///Classe usada para representar objetos constantes do tipo String
class CONSTANT_String_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_String_info(FILE *fp);
  ~CONSTANT_String_info();
  u2 string_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_String_info &);
};

/**
* Fields, methods, and interface methods are represented by similar structures:
* - tag: O atributo tag tem o valor da CONSTANT_Fieldref, CONSTANT_Methodref e CONSTANT_InterfaceMethodref, respectivamente 9, 10 e 11
* - class_index: Index válido na tabela de constant pool. A entrada constant_pool desse index deve ser uma estrutura CONSTANT_Class_info.
* - name_and_type_index: Index válido na tabela de constant pool. A entrada constant_pool desse index deve ser uma estrutura CONSTANT_NameAndType_info.
*/
class CONSTANT_Fieldref_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Fieldref_info(FILE *fp);
  ~CONSTANT_Fieldref_info();
  u2 class_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Fieldref_info &);
};


/// Tipo de entrada da Cp: Metodo de uma classe
/**
* Fields, methods, and interface methods are represented by similar structures:
* - tag: O atributo tag tem o valor da CONSTANT_Fieldref, CONSTANT_Methodref e CONSTANT_InterfaceMethodref, respectivamente 9, 10 e 11
* - class_index: Index válido na tabela de constant pool. A entrada constant_pool desse index deve ser uma estrutura CONSTANT_Class_info.
* - name_and_type_index: Index válido na tabela de constant pool. A entrada constant_pool desse index deve ser uma estrutura CONSTANT_NameAndType_info.
*/
class CONSTANT_Methodref_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_Methodref_info(FILE *fp);
  ~CONSTANT_Methodref_info();
  u2 class_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_Methodref_info &);
};

/**
* Fields, methods, and interface methods are represented by similar structures:
* - tag: O atributo tag tem o valor da CONSTANT_Fieldref, CONSTANT_Methodref e CONSTANT_InterfaceMethodref, respectivamente 9, 10 e 11
* - class_index: Index válido na tabela de constant pool. A entrada constant_pool desse index deve ser uma estrutura CONSTANT_Class_info.
* - name_and_type_index: Index válido na tabela de constant pool. A entrada constant_pool desse index deve ser uma estrutura CONSTANT_NameAndType_info.
*/
class CONSTANT_InterfaceMethodref_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_InterfaceMethodref_info(FILE *fp);
  ~CONSTANT_InterfaceMethodref_info();
  u2 class_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_InterfaceMethodref_info &);
};

/// A classe CONSTANT_NameAndType_info é utilizada para representar um field ou method, sem indicar qual tipo de classe ou interface ela pertence
class CONSTANT_NameAndType_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_NameAndType_info(FILE *fp);
  ~CONSTANT_NameAndType_info();
  u2 name_index;
  u2 descriptor_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_NameAndType_info &);
};

/* Classe utilizada para representar o Method handle */
class CONSTANT_MethodHandle_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_MethodHandle_info(FILE *fp);
  ~CONSTANT_MethodHandle_info();
  ///Deve ser de1 to 9. O valor denota o tipo do method handle que caracteriza o comportamento do bytecode
  u1 reference_kind;
  u2 reference_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_MethodHandle_info &);
};

class CONSTANT_MethodType_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_MethodType_info(FILE *fp);
  ~CONSTANT_MethodType_info();
  u2 descriptor_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_MethodType_info &);
};

/*Classe utilizada pela instrução invokedynamic para especificar um método bootstrap, o dynamic invocation name, o argumento e os tipos de retorno da chamada,
 sendo opcional a sequencia de constantes adicionais chamadas arumentos estaticos do metodo bootstrap */
class CONSTANT_InvokeDynamic_info : public CpInfo
{
public:
  /// construtor
  CONSTANT_InvokeDynamic_info(FILE *fp);
  ~CONSTANT_InvokeDynamic_info();
  u2 bootstrap_method_attr_index;
  u2 name_and_type_index;

private:
  friend std::ostream &operator<<(std::ostream &, const CONSTANT_InvokeDynamic_info &);
};
#endif
