#ifndef jvm_h
#define jvm_h

#include "definitions.h"

/*
* TODO: implementar as classes ClassesJVM, FramesPile e ObjectList
*       Criar método construtor de JVM
*
*/

class JVM {
  public:


  private:
    // Each Java Virtual Machine thread has a private Java Virtual Machine stack, created
    // at the same time as the thread.

    //ClassesJVM* classes;
    //FramesPile* frames;
    //ObjectList* object;
    u4 pc;
    u2 exception;
    char *exception_name;
};

#endif