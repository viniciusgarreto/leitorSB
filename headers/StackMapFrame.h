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

#ifndef stack_map_frame_h
#define stack_map_frame_h

#include <stdio.h>

#include "../headers/definitions.h"
#include "../headers/ConstantPool.h"
#include "../headers/Classes.h"
#include "../headers/LineNumberTable.h"
#include "../headers/VerificationTypeInfo.h"

class StackMapFrame {
  public:
    /// Construtor
    StackMapFrame(u1 tag);
    ~StackMapFrame();

    /// print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

    /***/
    static StackMapFrame* readStackMapFrame(FILE* fp);

  protected:
    u1 frame_type;
};

class SameFrame : public StackMapFrame {
  public:
    SameFrame(u1 tag);
    ~SameFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

class SameFrameExtended : public StackMapFrame {
  public:
    SameFrameExtended(u1 tag, FILE* fp);
    ~SameFrameExtended();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
};

class SameLocals1StackItemFrame : public StackMapFrame {
  public:
    SameLocals1StackItemFrame(u1 tag, FILE* fp);
    ~SameLocals1StackItemFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    VerificationTypeInfo* item;
};

class SameLocals1StackItemFrameExtended : public StackMapFrame {
  public:
    SameLocals1StackItemFrameExtended(u1 tag, FILE* fp);
    ~SameLocals1StackItemFrameExtended();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
    VerificationTypeInfo* item;
};

class ChopFrame : public StackMapFrame {
  public:
    ChopFrame(u1 tag, FILE* fp);
    ~ChopFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
};

class AppendFrame : public StackMapFrame {
  public:
    AppendFrame(u1 tag, FILE* fp);
    ~AppendFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
    vector<VerificationTypeInfo*> stack;
};

class FullFrame : public StackMapFrame {
  public:
    FullFrame(u1 tag, FILE* fp);
    ~FullFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
    u2 number_of_locals;
    u2 number_of_stack_items;
    vector<VerificationTypeInfo*> locals;
    vector<VerificationTypeInfo*> stack;
};

#endif
