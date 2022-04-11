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

    // deal with instance (we're using a singleton model)
    static JVM& getInstance();
    static void removeInstance();

    void ReadClassFile(string classfile_name);
    void execute();
    ClassFile& getClassFileByName(string classfile_name);

    u4 pc;
    u2 exception;

  private:
    // TODO: incluir lista de objetos
};

#endif
