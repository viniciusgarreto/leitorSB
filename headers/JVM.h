#ifndef jvm_h
#define jvm_h

#include "definitions.h"
#include <vector>
#include "Frame.h"

using namespace std;

typedef struct frameStack {
  list<frame> frames;
} FrameStack;

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
    vector<FrameStack> frame_stack;
    //ObjectList* object;
    u4 pc;
    u2 exception;
    char *exception_name;
};

#endif