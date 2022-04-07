#ifndef verification_type_info_h
#define verification_type_info_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/LineNumberTable.h"

class VerificationTypeInfo {
  public:
    VerificationTypeInfo(u1 tag);
    ~VerificationTypeInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

    static VerificationTypeInfo* readVerificationTypeInfo(FILE* fp);

  protected:
    u1 tag;
};

class TopVariableInfo : public VerificationTypeInfo {
  public:
    TopVariableInfo();
    ~TopVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class IntegerVariableInfo : public VerificationTypeInfo {
  public:
    IntegerVariableInfo();
    ~IntegerVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class FloatVariableInfo : public VerificationTypeInfo {
  public:
    FloatVariableInfo();
    ~FloatVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class LongVariableInfo : public VerificationTypeInfo {
  public:
    LongVariableInfo();
    ~LongVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class DoubleVariableInfo : public VerificationTypeInfo {
  public:
    DoubleVariableInfo();
    ~DoubleVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class NullVariableInfo : public VerificationTypeInfo {
  public:
    NullVariableInfo();
    ~NullVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class UninitializedThisVariableInfo : public VerificationTypeInfo {
  public:
    UninitializedThisVariableInfo();
    ~UninitializedThisVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class ObjectVariableInfo : public VerificationTypeInfo {
  public:
    ObjectVariableInfo(FILE* fp);
    ~ObjectVariableInfo();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 cpool_index;
};

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
