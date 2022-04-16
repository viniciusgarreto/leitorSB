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

#ifndef verification_type_info_h
#define verification_type_info_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/LineNumberTable.h"

/**
* @file VerificationTypeInfo.H
* @brief  A Verification Type especifica o tipo de um ou dois locais, onde um local
é uma única variável local ou uma única entrada na pilha de operandos. A Verification Type
é representado pela VerificationTypeInfo, que consiste
de uma tag de um byte, indicando qual item da união está em uso, seguido de zero ou
mais bytes, fornecendo mais informações sobre a tag.
*/

class VerificationTypeInfo {
  public:
    VerificationTypeInfo(u1 tag);
    ~VerificationTypeInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

    /**
    * @brief lê o verification type info do arquivo .class e a partir do valor de entrada lido, definindo assim a tag de entrada
    * @param fp - referencia para o arquivo class
    * @return VerificationTypeInfo - retorna o verification type info existente no arquivo .class
    */
    static VerificationTypeInfo* readVerificationTypeInfo(FILE* fp);

  public:
    u1 tag;
};

/// se a tag for = 0
class TopVariableInfo : public VerificationTypeInfo {
  public:
    TopVariableInfo();
    ~TopVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// se a tag for = 1
class IntegerVariableInfo : public VerificationTypeInfo {
  public:
    IntegerVariableInfo();
    ~IntegerVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};
/// se a tag for = 2
class FloatVariableInfo : public VerificationTypeInfo {
  public:
    FloatVariableInfo();
    ~FloatVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// se a tag for = 3
class LongVariableInfo : public VerificationTypeInfo {
  public:
    LongVariableInfo();
    ~LongVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// se a tag for = 4
class DoubleVariableInfo : public VerificationTypeInfo {
  public:
    DoubleVariableInfo();
    ~DoubleVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// se a tag for = 5
class NullVariableInfo : public VerificationTypeInfo {
  public:
    NullVariableInfo();
    ~NullVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// se a tag for = 6
class UninitializedThisVariableInfo : public VerificationTypeInfo {
  public:
    UninitializedThisVariableInfo();
    ~UninitializedThisVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// se a tag for = 7
class ObjectVariableInfo : public VerificationTypeInfo {
  public:
    ObjectVariableInfo(FILE* fp);
    ~ObjectVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 cpool_index;
};

/// se a tag for = 8
class UninitializedVariableInfo : public VerificationTypeInfo {
  public:
    UninitializedVariableInfo(FILE* fp);
    ~UninitializedVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset;
};

#endif
