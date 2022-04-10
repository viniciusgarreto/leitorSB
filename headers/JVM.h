#ifndef jvm_h
#define jvm_h

#include <vector>
#include "../headers/definitions.h"
#include "../headers/StackFrame.h"
#include "../headers/ClassFile.h"

using namespace std;

class JVM {
  public:
    JVM();
    ~JVM();

  private:
    u4 pc;
    u2 exception;
    char *exception_name;
    StackFrame* frame_stack;
    vector<ClassFile*> classes;

    // static Instructions instructions; // idk ?????
    // TODO: incluir lista de objetos
};

#endif
