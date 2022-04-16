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

/**
* @file StackMapFrame.h
* @brief Classe Stack Map Frame definida pelo atributo Stack Map Table,
union stack_map_frame {
  same_frame;
  same_locals_1_stack_item_frame;
  same_locals_1_stack_item_frame_extended;
  chop_frame;
  same_frame_extended;
  append_frame;
  full_frame;
}
*/
class StackMapFrame {
  public:
    /// Construtor
    StackMapFrame(u1 tag);
    ~StackMapFrame();

    /// print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

    /**
    * @brief lê o stack map frame do arquivo .class e a partir do valor de entrada lido, definindo assim o tipo do frame lido
    (classes herdeiras)
    * @param fp - referencia para o arquivo class
    * @return StackMapFrame - retorna o stack map frame existente no arquivo .class
    */
    static StackMapFrame* readStackMapFrame(FILE* fp);

  protected:
    /// tipo do frame
    u1 frame_type;
};

/// representada pelas tags no intervalo [0-63]
class SameFrame : public StackMapFrame {
  public:
    SameFrame(u1 tag);
    ~SameFrame();

    /// print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;
};

/// representada pela tag 251 
class SameFrameExtended : public StackMapFrame {
  public:
    SameFrameExtended(u1 tag, FILE* fp);
    ~SameFrameExtended();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
};

/// representada pelas tags no intervalo [64-127]
class SameLocals1StackItemFrame : public StackMapFrame {
  public:
    SameLocals1StackItemFrame(u1 tag, FILE* fp);
    ~SameLocals1StackItemFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    VerificationTypeInfo* item;
};

/// representada pela tag 247
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

/// representada pelas tags no intervalo [248-250]
class ChopFrame : public StackMapFrame {
  public:
    ChopFrame(u1 tag, FILE* fp);
    ~ChopFrame();

    // print methods
    ostream& print(unsigned int indent = 0, ostream& output = cout) const;

  protected:
    u2 offset_delta;
};

/// representada pelas tags no intervalo [252-254]
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

/// representada pela tag 255
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
